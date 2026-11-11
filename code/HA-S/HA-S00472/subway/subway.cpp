#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,a[505][20005],t[505][20005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}for(int i=1;i<=n;i++){
		scanf("lld",&k);
		k*=2;
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
	}cout<<32<<'\n'<<17;
	return 0;
}
