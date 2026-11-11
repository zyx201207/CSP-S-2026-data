#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define x first
#define y second
int const N=507,M=2e4+7;
int c,n,m,d,q;
vector<pii> g[N];
vector<int> p[N],lie[N];
ll a[N],ans,k[M][N]; 
bool vis[N];
int dis[N];
void dij(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<> > q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().y;q.pop();
		vis[u]=1;
		for(auto e:g[u]){
			int v=e.x,w=e.y;
			if(vis[v]) continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
ll op;
void dfs(int u,ll sum,int list,int s){
	if(u==s){
		op=min(op,sum+k[u][list]);
		return;
	}
	for(int v:p[u]){
		if(vis[v]) continue;
		for(int e:lie[v]){
			vis[v]=1;
			if(e==list) dfs(v,sum,list,s);
			else if(k[u][e]) dfs(v,sum+k[u][list]+k[u][e],e,s);
			vis[v]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	if(c>=7&&c<=11){
		while(n--){
			int w;cin>>w;
			if(w==2){
				int u,v_u,v,v_v;cin>>u>>v_u>>v>>v_v;
				g[u].push_back({v,v_u+v_v});
				g[v].push_back({u,v_u+v_v});
			}
		}
		while(q--){
			int l,r;cin>>l>>r;
			ans=a[l]+a[r];
			dij(l);
			cout<<ans+dis[r]<<'\n';
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int w,u=0,v,val;cin>>w;
			while(w--){
				cin>>v>>val;
				k[v][i]=val;
				lie[v].push_back(i);
				if(u){
					p[u].push_back(v);
					p[v].push_back(u);
				}
				u=v;
			}
		}
		while(q--){
			int l,r;cin>>l>>r;
			ans=a[l]+a[r],op=LLONG_MAX;
			memset(vis,0,sizeof(vis));
			vis[l]=1;
			for(int i=1;i<=n;i++){
				if(k[l][i]) dfs(l,k[l][i],i,r);
			}
			cout<<ans+op<<'\n';
		}
	}
	cout<<endl;
	return 0;
}
