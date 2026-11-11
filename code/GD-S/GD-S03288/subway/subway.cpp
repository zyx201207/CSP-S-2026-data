#include<bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

long long c, n, m, d, q, num;
long long tzk[N];
struct station{
	long long a, t, id;
}sta[500][N];//sta[i][j] 表示第i条线的第j个站的信息 
long long w[5005][5005];
vector<pair<long long, long long>> st[N];//st[i]表示第i个站有哪些线经过 
set<long long> b;//记录一共有哪些站 

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(long long i = 1;i <= m;i++) cin >> tzk[i];
	for(long long i = 1;i <= 5000;i++) {
		for(long long j = 1;j <= 5000;j++) {
			w[i][j] = 1e16;
		}
	}
	for(long long i = 1;i <= n;i++) {
		long long k;
		cin >> k;
		for(long long j = 1;j <= k;j++) {
			cin >> sta[i][j].a >> sta[i][j].t;
			sta[i][j].id = ++num;
			st[sta[i][j].a].push_back({i, j}); 
			b.insert(sta[i][j].a);
		}
		for(long long j = 1;j <= k;j++) {
			for(long long g = 1;g <= k;g++) {
				w[sta[i][j].id][sta[i][g].id] = 0;
			}
		}
	}
	for(auto v : b) {
		if(st[v].size() > 1) {
			for(long long i = 0;i < st[v].size();i++) {
				for(long long j = 0;j < st[v].size();j++) {
					if(i == j) continue;
					w[sta[st[v][i].first][st[v][i].second].id][sta[st[v][j].first][st[v][j].second].id] = sta[st[v][i].first][st[v][i].second].t + sta[st[v][j].first][st[v][j].second].t;
				}
			}
		}
	}
	for(long long i = 1;i <= num;i++) {
		for(long long j = 1;j <= num;j++) {
			for(long long k = 1;k <= num;k++) {
				w[i][k] = min(w[i][k], w[i][j] + w[j][k]);
			}
		}
	}
	while(q--) {
		long long x, y;
		cin >> x >> y;
		long long ans = 0, minn = 1e18;
		ans += tzk[x] + tzk[y];
		for(long long i = 0;i < st[x].size();i++) {
			for(long long j = 0;j < st[y].size();j++) {
				minn = min(minn, w[sta[st[x][i].first][st[x][i].second].id][sta[st[y][j].first][st[y][j].second].id] + sta[st[x][i].first][st[x][i].second].t + sta[st[y][j].first][st[y][j].second].t);
			}
		}
		cout << ans + minn << '\n';
	}
	return 0;
}
