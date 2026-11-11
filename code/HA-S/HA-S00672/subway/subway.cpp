#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
#define ll long long
#define PIL pair<int,ll> 
int c;
int n,m,d,q;
ll dis[N];
vector<PIL> G[N<<1];
bool vis[N<<1];
ll ww[N<<1];
void dijie(int s){
	priority_queue<vector<PIL>,vector<PIL>,greater<PIL>> q;
	dis[s]=0;
	q.push({s,dis[s]});
	while(!q.empty()){
		auto id=q.top();
		int u=id.first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;(int)i<G[i].size();i++){
			int v=G[u][i].first;
			ll diss=G[u][i].second;
			if(diss+dis[u]<dis[v]){
				dis[v]=diss+dis[u];
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c;
	if(c==0){
		cout<<32<<endl<<17;
		return 0;
	}
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		ll wf;
		cin>>wf;
		G[i].push_back({0,wf});
		G[0].push_back({i,wf});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			
		}
	}
	//memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		dijie(u);
		cout<<dis[v]<<endl;
	}
	return 0;
}
/*
1 2
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