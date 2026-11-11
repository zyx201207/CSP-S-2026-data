#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e3+10,inf=0x3f3f3f3f3f3f3f3f;
int x[maxn];vector<int>G[maxn],D[maxn];
int dis[maxn],deg[maxn],f[maxn];queue<int>q;
void solve(){
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int u=1;u<=n;u++)G[u].clear();
	for(int u=1;u<=n;u++)
		for(int v=u+1;v<=n;v++)
			if(x[v]-x[u]<=d)G[u].push_back(v);
	int res=0;
	for(int rt=n;rt>=1;rt--){
		for(int u=1;u<=n;u++)D[u].clear();
		memset(dis,0x3f,sizeof dis);
		q.push(rt);dis[rt]=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int v:G[u])
				if(dis[v]>dis[u]+1)
					dis[v]=dis[u]+1,q.push(v);
		}
		for(int u=1;u<=n;u++)
			for(int v:G[u])
				if(dis[v]==dis[u]+1)
					D[u].push_back(v),deg[v]++;
		memset(f,0,sizeof f); 
		q.push(rt);f[rt]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int v:D[u]){
				f[v]+=f[u];
				if(!--deg[v])q.push(v);
			}
		}
		int cnt=0;
		for(int u=1;u<=n;u++)
			res+=f[u]==2,cnt+=f[u]==2;
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
