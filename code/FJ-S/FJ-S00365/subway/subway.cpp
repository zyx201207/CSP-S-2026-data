#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=1e6+5;
int c,n,m,d,Q,cnt,s,t;
int w[N];
map<int,int>dis[N];
vector<pair<int,int>>g[M];
void dij(int s) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1; i<=cnt; i++)dis[s][i]=1e18;
	dis[s][s]=0;
	q.push({0,s});
	while(!q.empty()) {
		auto z=q.top();
		q.pop();
		int x=z.second;
		int ww=z.first;
		if(dis[s][x]!=ww)continue;
		for(auto t:g[x]) {
			int y=t.first;
			int p=t.second;
			if(dis[s][y]>ww+p) {
				dis[y][s]=dis[s][y]=ww+p;
				q.push({ww+p,y});
			}
		}
	}
	return;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1; i<=m; i++)cin>>w[i];
	cnt=m;
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int a,t;
			cin>>a>>t;
			g[a].push_back({++cnt,t});
			g[cnt].push_back({a,t});
			if(j>1) {
				g[cnt].push_back({cnt-1,0});
				g[cnt-1].push_back({cnt,0});
			}
		}
	}
	while(Q--) {
		cin>>s>>t;
		if(dis[s][t]==0)dij(s);
		cout<<dis[s][t]+w[s]+w[t]<<endl;
	}
	return 0;
}
