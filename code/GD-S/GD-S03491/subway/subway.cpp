#include<bits/stdc++.h>
using namespace std;
struct trans{
	int line;
	int ti;
};
const int N = 505;
const int M = 5e5 + 5;
const int Q = 1e5 + 5;
int c, n, m, d, q, w[M], k[N], a, t, x, y;
vector<trans> sta[M];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; i++){
			cin >> a >> t;
			sta[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> x >> y;
		cout << w[x] + w[y] + sta[1][1].ti * 2 << endl;
	}
	return 0;
}

