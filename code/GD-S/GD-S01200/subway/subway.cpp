#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N=5e5+10;
int c,m,n,d,Q;
int dis[N],vis[N],w[N];
vector<PII> g[N];
priority_queue<PII,vector<PII>,greater<PII>> q;
void dij(int s){
	for(int i=0;i<=n+m;i++) dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
	q.push({0,s});dis[s]=0;
	while(q.size()){
		int tmp=q.top().second;q.pop();
		if(vis[tmp]) continue;
		vis[tmp]=1;
		for(PII u:g[tmp]){
			int v=u.first,W=u.second;
			if(dis[v]>dis[tmp]+W){
				dis[v]=dis[tmp]+W;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back({i+m,y}),g[i+m].push_back({x,y});
		}
	}
	while(Q--){
		int s,t;
		cin>>s>>t;
		dij(s);
		cout<<dis[t]+w[s]+w[t]<<endl;
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
