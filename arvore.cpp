#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node Node;

struct node {
	int valor;
	Node *direita;
	Node *esquerda;
};

Node *alocarNovoNode(int valor);	
Node *inserir(Node *raiz, int valor);
Node *buscarItem(Node *raiz, int valor);
Node *valorMaximo(Node *raiz);
Node *valorMinimo(Node *raiz);
int altura(Node *raiz);

int main() {
	setlocale(LC_ALL, "Portuguese");
	Node *arvore = NULL;
	Node *max, *min;
	int op=1;
	do {
		system("cls");
		printf(" 1. para inserir um elemento na árvore binária;");
		printf("\n 2. para obter o maior valor armazenado;");
		printf("\n 3. para obter o menor valor armazenado;");
		printf("\n 4. para obter a altura da árvore binária.");
		printf("\n 0. para sair.\n");
		scanf("%d", &op);
		
		switch(op) {
			case 0:
				break;
			
			case 1:
				int valor;
				printf("\nInsira o valor a ser inserido: ");
				scanf("%d", &valor);
				arvore = inserir(arvore, valor);
				break;
			case 2:
				max = valorMaximo(arvore);
				printf("\nValor máximo armazenado: %d\n", max->valor);
				system("pause");
				break;
			case 3:
				min = valorMinimo(arvore);
				printf("\nValor mínimo armazenado: %d\n", min->valor);
				system("pause");
				break;
			case 4:
				int alturaArvore = altura(arvore);
				printf("\nAltura da árvore binária: %d\n", alturaArvore);
				system("pause");
				break;
			
		}
		
	} while(op!=0);
}

Node *alocarNovoNode(int valor) {
	Node *novo = (Node*)malloc(sizeof(Node));
	novo->valor = valor;
	novo->esquerda = NULL;
	novo->direita = NULL;
	
	return novo;
}

Node *inserir(Node *raiz, int valor) {
	if(raiz == NULL) {
		Node *novo = alocarNovoNode(valor);
		return novo;
	} else {
		if(valor < raiz->valor) { //inserir a esquerda
			raiz->esquerda = inserir(raiz->esquerda, valor);
		}
		else if(valor>raiz->valor) { //inserir a direita
			raiz->direita = inserir(raiz->direita, valor);
		}
		else {
			printf("Valor já inserido!");
		}
	}
	return raiz;
}

Node *buscarItem(Node *raiz, int valor) {
	if(raiz == NULL) {
		printf("O valor: %d não está inserido na árvore.", valor);
		return NULL;
	} 
	else {
		if(valor< raiz->valor) {
			return buscarItem(raiz->esquerda, valor);
		}
		else if(valor> raiz->valor) {
			return buscarItem(raiz->direita, valor);
		}
		else {
			return raiz;
		}
	}
}
Node *valorMaximo(Node *raiz) {
	if(raiz == NULL) {
		return NULL;
	}
	else {
		if(raiz->direita == NULL) {
			return raiz;
		} else {
			return raiz->direita = valorMaximo(raiz->direita);
		}
	}
	
}
Node *valorMinimo(Node *raiz) {
	if(raiz == NULL) {
		return NULL;
	}
	else {
		if(raiz->esquerda == NULL) {
			return raiz;
		} else {
			return raiz->esquerda = valorMinimo(raiz->esquerda);
		}
	}
	
}

int altura(Node *raiz) {
	if(raiz == NULL) {
		return 0;
	} 
	else {
		int alturaEsquerda, alturaDireita;
		alturaEsquerda = altura(raiz->esquerda);
		alturaDireita = altura(raiz->direita);
		
		if(alturaDireita > alturaEsquerda) {
			return altura(raiz->direita) + 1;
		} else	{
			return altura(raiz->esquerda) + 1;
		} 
	}
}