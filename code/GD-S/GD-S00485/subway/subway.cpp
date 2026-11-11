#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int cc,n,m,dd,qe,w[N],a[505][5003],ti[505][5003],dis[5003][5005],k[505];
bool vis[N];
struct tu{
	int i,di,id;
	friend bool operator<(tu x,tu y){return x.di>y.di;}
};
vector<pair<int,int> >ve[N];
priority_queue<tu>q;
void dijkstra(int s){
	for(int i=1;i<=m;i++) dis[s][i]=1e18,vis[i]=0;
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		int t=q.top().i;
		q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(auto it:ve[t]){
			int nx=it.first,co=it.second;
			if(dis[s][nx]>dis[s][t]+co){
				dis[s][nx]=dis[s][t]+co;
				q.push({nx,dis[s][nx]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cc>>n>>m>>dd>>qe;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>ti[i][j];
			if(j>1){
				ve[a[i][j-1]].push_back({a[i][j],ti[i][j]});
				ve[a[i][j]].push_back({a[i][j-1],ti[i][j-1]});
				cout<<a[i][j]<<'\n';
			}
			ve[0].push_back()
		}
	}
	for(int i=1;i<=m;i++){
		for(auto it:ve[i]) cout<<it.first<<' '<<it.second<<'\n';
		cout<<'\n';
	}
	for(int i=1;i<=m;i++) dijkstra(i);
	while(qe--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
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
*/
