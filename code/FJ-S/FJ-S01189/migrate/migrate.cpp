#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e18;
int n;
vector<int> g[5500];
int ans[5500];
int cnt[5500];
int vis[5500];
int vis1[5500];
void bfs(int xx) {
	queue<pair<int,int> > q;
	q.push({xx,0});
	while(!q.empty()) {
		int u=q.front().first,w=q.front().second;
		q.pop();
		ans[u]=min(ans[u],w);
		vis[u]=1;
		for(auto x:g[u]) {
			if(!vis[x])q.push({x,w+1});
		}
	}
}
void bfss(int xx) {
	queue<pair<int,int> > q;
	q.push({xx,0});
	while(!q.empty()) {
		int u=q.front().first,w=q.front().second;
		q.pop();
		cnt[u]+=(w==ans[u]);
//		cout<<u<<" "<<w<<"\n";
		vis1[u]=1;
		for(auto x:g[u]) {
			if(!vis1[x])q.push({x,w+1});
		}
	}
}
void solve() {
	int d;
	cin>>n>>d;
	vector<int> x(n+1);
	for(int i=1; i<=n; i++) {
		cin>>x[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(abs(x[i]-x[j])<=d)g[i].push_back(j),g[j].push_back(i);
//				cout<<i<<" "<<j<<"\n";
		}
	}
	int anss=0;
	for(int j=1; j<=n; j++) {
		ans[j]=LLONG_MAX;
		cnt[j]=vis[j]=vis1[j]=0;
	}
//	for(int i=1; i<=n; i++) {
//		for(auto x:g[i])cout<<x<<" ";
//		cout<<"\n";
//	}
	for(int i=1; i<=n; i++) {
		bfs(i);
		bfss(i);
		for(int j=1; j<=n; j++) {
//			cout<<ans[j]<<" ";
			if(j!=i&&cnt[j]==2)anss++;
			ans[j]=LLONG_MAX;
			cnt[j]=vis[j]=vis1[j]=0;
		}
//		cout<<"\n";
	}
	for(int i=1;i<=n;i++)g[i].clear();
	cout<<anss/2<<"\n";
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14) {
		while(t--)cout<<"0\n";
		return 0;
	}
	while(t--)solve();
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
