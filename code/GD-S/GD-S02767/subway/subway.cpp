#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define F first
#define S second
using namespace std;
const int M=505,N=5e5+10;
ll w[N],k[N],c,n,m,d,q,x,y,l=1,r=2,sum=0,ans=1;
bool vis[N];
vector <ll> g[M],h[N],a[M],t[M];
ll dist_same(ll x,ll y,ll id){
	return t[id][x]+t[id][y];
}
void dfs(ll x,ll ed,ll s){
	vis[x]=1;
	for(auto cnt:g[x]){
		for(int i=1;i<=k[cnt];i++){
			if(a[cnt][i]==x||vis[x]) continue;
			else if(a[cnt][i]==ed) {
				sum=min(s+dist_same(x,ed,cnt),sum);
				return;
			}
			ll dis=dist_same(x,a[cnt][i],cnt);
			if(s+dis>sum) return;
			dfs(a[cnt][i],ed,s+dis);
		}
	}
	vis[x]=0;
}
ll solve(ll st,ll ed){
	sum=1e18;
	for(auto cnt1:g[st])
		for(auto cnt2:g[ed]) if(cnt1==cnt2) sum=min(sum,dist_same(cnt1,st,ed));
	//处理同线
	dfs(st,ed,0);
	//处理换乘 
	return sum+w[st]+w[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		scanf("%lld",k+i);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			g[a[i][j]].PB(i),h[i].PB(a[i][j]);
		} 
	}
	for(int i=1;i<=q;i++) {
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",solve(x,y));
	}
 	return 0;
}
