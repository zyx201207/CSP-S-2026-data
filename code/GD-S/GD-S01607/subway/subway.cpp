#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
using namespace std;
const int MAXN=5e2+5,MAXM=5e5+5;
int c,n,m,d,q,w[MAXM],k[MAXM],x,y,dist[MAXM];
bool vis[MAXM];vector<PII>e1[MAXN],e2[MAXN];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++)
			cin>>x>>y,e1[x].push_back({i,y}),e2[i].push_back({x,y});
	}while(q--){
		int x,y;
		cin>>x>>y;
		priority_queue<PII,vector<PII>,greater<PII>>q;
		for(int i=1;i<=m;i++)dist[i]=1e18,vis[i]=false;
		dist[x]=0,q.push({0,x});while(!q.empty()){
			int x=q.top().second;q.pop();
			if(vis[x])continue;vis[x]=true;
			for(auto u:e1[x])
				for(auto v:e2[u.first])
					if(dist[v.first]>dist[x]+u.second+v.second)
						dist[v.first]=dist[x]+u.second+v.second,q.push({dist[v.first],v.first});
		}if(dist[y]==1e18)cout<<"-1\n";else cout<<dist[y]+w[x]+w[y]<<'\n';
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
(32,17)

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
(35,16)
*/
