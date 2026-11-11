#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,xx,yy,ans,minn=1e11;
long long w[5005],a[5005][5005],t[5005][5005];
void dfs(int x,int y){
	for(int i=1;i<=yy;i++){
		for(int j=1;j<=yy;j++){
			minn=min(minn,t[i][j]);
		}
		ans+=minn;
		minn=1e11;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&xx,&yy);
		ans=w[xx]+w[yy];
		dfs(xx,yy);
		printf("%lld\n",ans);
	}
	return 0;
}
