#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+5, N = 505;
int w[M];
int k[N];
int a[N][M], t[N][M];
int c,n,m,d,q;
vector<pair<int, int> > adj[N]; 
// adj[u] = (v, w) 
void solve(int x, int y) {
	int ans = w[x] + w[y];
	while(x != y) {
		ans += adj[x][0].second;
		x = adj[x][0].first;
	}
	cout<<ans<<endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		if(k[i] == 2) {
			pair<int,int> aa = make_pair(a[i][2], t[i][2] + t[i][a[i][2]]), bb = make_pair(a[i][1], t[i][1] + t[i][a[i][1]]);
			adj[a[i][1]].push_back(aa);
			adj[a[i][2]].push_back(bb);
		}
	}
	for(int i=1; i<=n; i++) {
		int x,y; cin>>x>>y;
		solve(x, y);
	}
	return 0;
}
