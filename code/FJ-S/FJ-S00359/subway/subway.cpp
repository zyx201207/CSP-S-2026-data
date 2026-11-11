#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],dis[505005],vis[505005],y,ans=1e17;
vector<pair<int,int>>v[505005];
//地铁线的点+mov 
void dij(int s){
	priority_queue<pair<int,int>>q;
	q.push({0,s});
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(auto p:v[x]){
			int to=p.first,w=p.second;
			if(dis[to]>dis[x]+w){
				dis[to]=dis[x]+w;
				q.push({-dis[to],to});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			v[i+m].push_back({a,t});
			v[a].push_back({i+m,t});
		}
	}
	while(q--){
		int x;
		cin>>x>>y;
		ans=1e17;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
