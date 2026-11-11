#include <bits/stdc++.h>
using namespace std ;

struct node {
	int n, m ;
	char sit ;
} ;

node R, X ;
int main() {
	freopen("travel.in", "r", stdin) ;
	freopen("travel.out", "w", stdout) ;
	
//	freopen("travel5.in", "r", stdin) ;
//	freopen("travel5.out.txt", "w", stdout) ;
	// travel1 OkClear!
	// travel2 OkClear!
	// travel3 OkClear!
	// travel4 OkClear!
	// travel5 OkClear!
	
	
	scanf("%d %d %c %d %d %c", &R.n, &R.m, &R.sit  ,  &X.n, &X.m, &X.sit) ;
	
	if(R.n != X.n) printf("0000") ;
	else {
		printf("1") ;
		if(R.m != X.m) printf("000") ;
		else {
			printf("1") ;
			int Rit = R.sit - 'A' + 1, Xit = X.sit - 'A' + 1 ;
			// A B C | D E
			// 1 2 3 | 4 5
			if(Rit < 4 && Xit < 4 || Rit > 3 && Xit > 3) {
				printf("1") ;
				if(Rit > Xit) swap(Rit, Xit) ;
				if(Rit == 1 && Xit == 3) printf("0") ;
				else printf("1") ;
			}
			else printf("00") ;
		}
	}
	
	printf("\n") ;
	return 0 ;
}

