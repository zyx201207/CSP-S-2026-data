#include <bits/stdc++.h>
using namespace std;

long long n,m,A[1000006],T[1000006],S[1000006];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i]);
		T[A[i]]++;
	}
	for(int i=1;i<=m;i++){
		S[i]=S[i-1]+T[i];
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",S[i]);
	}
	
	return 0;
} 
