#include<bits/stdc++.h>
#define IL inline
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define ri register int
#define F(i,a,b) for(ri i=a;i<=b;i++)
#define FF(i,a,b) for(ri i=b;i>=a;i--)
#define vec vector
using namespace std;
const int N=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-9;
int c,n,m,d,q,tot,k,a,t,x,y;
ll w,dist[N];
bool vis[N];
vec<pair<int,ll>> g[N];
IL ll dijkstra(int s,int t){
	priority_queue<pair<ll,int>,vec<pair<ll,int>>,greater<pair<ll,int>>> pq;
	F(i,1,tot) dist[i]=inf,vis[i]=0;
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		auto [w,u]=pq.top(); pq.pop();
		if(dist[u]!=w) continue;
		for(auto [v,d]:g[u]){
			if(dist[u]+d<dist[v]){
				dist[v]=dist[u]+d;
//				cout<<"v:"<<v<<" dist_v:"<<dist[v]<<'\n';
				if(!vis[v]){
					pq.push({dist[v],v});
					vis[v]=1;
				}
			}
		}
	}
//	F(i,1,tot) cout<<"dist_i:"<<dist[i]<<'\n';
//	cout<<'\n';
	return (dist[t]!=inf?dist[t]:-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	tot=m;
	F(i,1,m){
		cin>>w;
		++tot;
		g[i].emplace_back(tot,w);
		g[tot].emplace_back(i,w);
	}
	F(i,1,n){
		cin>>k;
		++tot;
		F(i,1,k){
			cin>>a>>t;
			g[tot].emplace_back((a+m),t);
			g[(a+m)].emplace_back(tot,t);
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dijkstra(x,y)<<'\n';
	}
	return 0;
}
/*
样例 1:
in:
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
out:
32
17

样例 2:
in:
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
out:
35
16

大力 dij 似乎能骗 50pts 左右
相信西西弗数据.jpg 
*/
