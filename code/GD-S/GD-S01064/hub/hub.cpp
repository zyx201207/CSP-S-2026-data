#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
int cid,T;
ll n,k,u[N],v[N],dis[N];
int f[N];
bool vis[N];
vector<int>g[N];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		g[i].clear();
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	long long ans=1e18;
	for(int mask=1;mask<(1<<n);mask++){
		if(__builtin_popcount(mask)!=k)continue;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<n;i++){
			if(((mask>>u[i])&1)&&((mask>>v[i])&1)){
				int fa=find(u[i]),fb=find(v[i]);
				f[u[i]]=v[i];
			}
		}
		int allsum=0;
		for(int i=1;i<=n;i++)
			if((mask>>i&1)&&f[i]==i)allsum++;
		if(allsum>2)continue;
		queue<int>q;
		for(int i=1;i<=n;i++)dis[i]=1e9;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
			if(mask>>i&1){
				q.push(i);
				vis[i]=1;
				dis[i]=0;
			}
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int v:g[u]){
				dis[v]=min(dis[v],dis[u]+1);
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
		long long maxd=0;
		for(int i=1;i<=n;i++)
			maxd=max(maxd,dis[i]);
		ans=min(ans,maxd);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>cid>>T;
	while(T--)
		solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
