//GZ-J00415 兴义市弘毅中学 程峻熙 
#include<bits/stdc++.h>
using namespace std;
long long a,b,c[1000010],d[1000010],e[1000010],g[1000010],f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf('%lld%lld',&a,&b);
	for(int i=1;i<=a;i++){
		scanf("%lld",&c[i]);
	}
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			if(e[c[j]]) f=e[c[j]];
			d[++f]=c[j],e[c[j]]=f;
		}
		for(int j=1;j<=a;j++){
			g[d[j]]++;
		}
	}
	for(int i=1;i<=b;i++){
		printf("%lld ",g[i]);
	}
	return 0;
}
