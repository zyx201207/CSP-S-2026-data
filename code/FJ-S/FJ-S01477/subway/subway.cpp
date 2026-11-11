#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=50005;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q;
ll w[N];
ll k[505],a[505][N],t[505][N];
ll x,y;
bool vis[N];
ll dfs(ll l,ll r){
	if(l==r) return 0;
	vis[l]=true;
	ll ans=INF;
	ll b;
	for(int i=1;i<=n;i++){
		b=0;
		for(int j=1;j<=k[i];j++) if(a[i][j]==l) b=t[i][j];
		if(b){
			for(int j=1;j<=k[i];j++){
				if(!vis[a[i][j]]) ans=min(ans,dfs(a[i][j],r)+t[i][j]+b);
			}
		}
	}
	vis[l]=false;
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",dfs(x,y)+w[x]+w[y]);
	}
	return 0;
}
