#include<bits/stdc++.h>
using namespace std;
string w,s;
long long n,m,a[10000001],x,ans,b[10000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			b[a[j]]++;
		}
	}
	for(int i=1; i<=m; i++){
		printf("%lld ",b[i]);
	} 
	return 0;
} 
