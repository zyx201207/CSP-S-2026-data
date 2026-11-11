#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int INF = 0x3f3f3f;
const int N = 1e4+5;

int c,n,m,d,q,x,y,owo[N];
int w[N],ki[N];
int a[N][N],t[N][N];
struct line{
	int k,o;
};
vector<line> f[N];

void dfs(int u,int lk,int ns) {
	int sum = t[lk][f[u][lk].o];
	if(ns == y) {
		owo[u] = sum+t[lk][f[ns][lk].o]+w[ns];
		return;
	}

	int ss = INF;
	for(int l=0; l < f[ns].size(); l++) {
		int kj = f[ns][l].k,oj = f[ns][l].o;
		if(kj == lk) continue;
		for(int i=oj+1; i <= ki[kj]; i++) {
			dfs(ns,kj,a[kj][i]);
			ss = min(ss, t[kj][i]+owo[a[kj][i]]);
		}
	}
	owo[u] = min(owo[u],sum+ss);
	return;
}

void solve() {
	memset(owo,INF,sizeof owo);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i <= m; i++) cin >> w[i];
	for(int i=1; i <= n; i++) {
		cin >> ki[i];
		for(int j=1; j <= ki[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			f[a[i][j]].push_back({i,j});
		}
	}
	
	while(q--) {
		cin >> x >> y;
		for(int i=1; i <= m; i++) {
			if(i == x) continue;
			dfs(x,0,i);
		}
		cout << owo[x]+w[x] << endl;
	}
	return;
}

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int T=1;
//  cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}