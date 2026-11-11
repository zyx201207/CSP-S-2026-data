#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'
#define min(a,b) (a<b?a:b)
using namespace std;
const int N=5e2+5;
const int M=5e5+5;
struct node{
	int id;
	ll v;
	bool operator>(const node &b)const{
		return v>b.v;
	}
};
struct edge{
	int to;
	ll w;
};
ll n,m,d,q,w[M],k[N],hc[N][N],dis[N];
bool vis[N];
vector<ll>st[M];
vector<edge>e[N];
unordered_map<int,ll>mp[N];
priority_queue<node,vector<node>,greater<node>>pq;
void dij(int s){
	fill(dis,dis+N,1e18);
	memset(vis,0,sizeof(vis));
	for(int v:st[s]){
		dis[v]=mp[v][s];
		pq.push({v,dis[v]});
	}
	while(!pq.empty()){
		int u=pq.top().id;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ed:e[u]){
			int v=ed.to;
			ll w=ed.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
			}
		}
	}
}
int main(){
//	system("fc subway7.out subway7.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			mp[i][x]=y;
			st[x].push_back(i);
		}
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			hc[i][j]=1e18;
	for(int i=1;i<=m;i++){
		for(auto &s1:st[i]){
			for(auto &s2:st[i]){
				if(s1==s2) continue;
				hc[s1][s2]=hc[s2][s1]=min(hc[s1][s2],mp[s1][i]+mp[s2][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||hc[i][j]>=1e18) continue;
			e[i].push_back({j,hc[i][j]});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		ll ans=1e18;
		for(auto s:st[y])
			ans=min(ans,dis[s]+mp[s][y]);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
