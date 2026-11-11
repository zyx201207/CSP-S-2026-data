#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int test,m,n,d,t;
int sx,ex;
int dis[N];
int s[N];
int mindown[N];
bool vis[N];
struct edge{
	int v,w;
};
vector<edge> g[N];
vector<edge> pos[N];
vector<int> tag[N],a[N];
struct node{
	int u,dist;
	inline bool operator<(const node &x) const{
		return dist>x.dist;
	}
};
priority_queue<node> q;
void dij(int st){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto&T:g[u]){
			int v=T.v,w=T.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>test>>m>>n>>d>>t;
	for(int i=1;i<=n;++i)
		cin>>s[i];
	for(int i=1;i<=m;++i){
		int k,v,w;
		cin>>k;
		while(k--){
			cin>>v>>w;
			pos[i].push_back({v,w});
			tag[v].push_back(i);
			a[v].push_back(w);
			mindown[i]=min(mindown[i],w);
		}
	}
	for(int i=1;i<=m;++i)
		for(auto&T:pos[i]){
			int u=T.v,w=T.w;
			for(auto&v:tag[u]){
				if(i==v) continue;
				int mincos=LLONG_MAX;
				for(auto&TT:pos[v]){
					int ww=TT.w;
					mincos=min(mincos,w+ww);
//					if(mincos==8) cout<<"w&ww: "<<w<<' '<<ww<<'\n';
				}
				g[i].push_back({v,mincos});
				g[v].push_back({i,mincos});
				if(mincos==8){
//					cout<<"here! "<<i<<' '<<u<<' '<<w<<' '<<v<<'\n';
				}
			}
		}
//	for(int i=1;i<=m;++i)
//		for(auto&T:g[i]){
//			int v=T.v,w=T.w;
//			cout<<"edge: "<<i<<' '<<v<<' '<<w<<'\n';
//		}
	while(t--){
		cin>>sx>>ex;
		int ans=LLONG_MAX;
		int ext=s[sx]+s[ex];
		for(auto&u:tag[sx]){
			dij(u);
			for(auto&v:tag[ex])
				ans=min(ans,dis[v]+mindown[u]+mindown[v]);
		}
		cout<<ans+ext<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
-----
32
17

i'm loser.
@Super_Diu (uid=1057013)
AFO. 100+0+0+0.
*/
