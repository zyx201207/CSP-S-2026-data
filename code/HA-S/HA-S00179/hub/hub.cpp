#include<bits/stdc++.h>
#define ll long long
#define N 4001
#define INF 4e18 
using namespace std;
ll c,t,n,k,u,v,ans,dis[N],a[N];
vector<ll> e[N];
bool vis[N],vis2[N];
void bfs(ll x){
	queue<pair<ll,ll> > q;
	q.push({x,0});
	for(int i=1;i<=n;i++) vis2[i]=false;
	while(q.size()){
		pair<ll,ll> now=q.front();
		q.pop();
		vis2[now.first]=true;
		if(dis[now.first]>now.second){
			dis[now.first]=now.second;
			for(int i=0;i<e[now.first].size();i++)
			if(!vis2[e[now.first][i]]) q.push({e[now.first][i],now.second+1});
		}
	}
	return ;
}
void dfs(ll x){
	if(x==k+1){
		for(int i=1;i<=n;i++) dis[i]=n;
		for(int i=1;i<=k;i++) bfs(a[i]);
		//for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		//cout<<endl; 
		ll num=0;
		for(int i=1;i<=n;i++) num=max(num,dis[i]);
		ans=min(ans,num);
		return ;
	}
	for(int i=1;i<=n;i++)
	if(!vis[i]){
		vis[i]=true;
		a[x]=i;
		dfs(x+1);
		vis[i]=false;
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=INF;
		dfs(1);
		cout<<ans<<endl; 
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
} 
