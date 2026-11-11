#include <bits/stdc++.h>
using namespace std;
long long m,n,am[500010],g,aminm=100000000001,add;
bool ia=false;

long long cr(){
	for(int i=aminm;i<m;i++){
		add=0;
		g=0;
		for(int w=0;w<n&&add<=m;w++){
			if(am[w]<=i){
				long long k=am[w]-i;
				if(k<0){
					add=add-k;
				}else{
					add=add+k; 
				}
				g++;
			}
		}
		if(g==n||i==m){
			return g;
		}
		if(add>=m){
			return g;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=0;i<n;i++){
		long long in1;
		scanf("%lld",&in1);
		am[i]=in1;
		aminm=min(aminm,in1);
	}
	printf("%lld",cr());
	return 0;
}
