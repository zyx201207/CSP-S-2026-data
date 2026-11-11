#include<iostream>
#include<vector> 
#include<map>
#include<queue>
#include<cmath>
using namespace std;
const int M=5e5+5;
int c,n,m,d,q,wi,rp[M];
vector<pair<int,int>>g[M*23];
map<int,int>mp2[M];
bool vis[M*23];
long long dis[M*23];
void solve(){
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=23*m;i++){
		vis[i]=false;
		dis[i]=2e18;
	}
	priority_queue<pair<int,int>>q;
	q.push(make_pair(0,x));
	dis[x]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		vis[u]=true;
		for(pair<int,int>x:g[u]){
			int v=x.first;
			int w=x.second;
			if(vis[v])continue;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	cout<<dis[y]<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>wi;
		g[i+m].push_back(make_pair(i,wi));
		g[i].push_back(make_pair(i+m,wi));
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int lst=0;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			++rp[a];
			mp2[a][i]=rp[a];
			g[(rp[a]+1)*m+a].push_back(make_pair(m+a,t));
			g[m+a].push_back(make_pair((rp[a]+1)*m+a,t));
			if(lst!=0){
				g[lst+(mp2[lst][i]+1)*m].push_back(make_pair((rp[a]+1)*m+a,0));
				g[(rp[a]+1)*m+a].push_back(make_pair(lst+(mp2[lst][i]+1)*m,0));
			}
			lst=a;
		}
	}
	while(q--){
		solve();
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
