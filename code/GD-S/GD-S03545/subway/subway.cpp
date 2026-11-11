#include <bits/stdc++.h>
using namespace std;
int w[501000];
vector<pair<int, int>> e[501000];
long long f[501000];
pair<int, int> qqq[210000];
long long ans[110000];
vector<pair<int, int>> eq[510]; 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, qq;
	cin >> c >> n >> m >> d >> qq;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		while (x--){
			int y, z;
			cin >> y >> z;
			e[y].push_back({i + m, z});
			e[i + m].push_back({y, z});
		}
	} 
	for (int i = 1; i <= qq; i++){
		ans[i] = 1000000000000000000;
		cin >> qqq[i].first >> qqq[i].second;
		for (int j = 0; j < e[qqq[i].first].size(); j++){
			eq[e[qqq[i].first][j].first - m].push_back({i, e[qqq[i].first][j].second});
		}
		qqq[i + qq] = {qqq[i].second, qqq[i].first};
		for (int j = 0; j < e[qqq[i].second].size(); j++){
			eq[e[qqq[i].second][j].first - m].push_back({i + qq, e[qqq[i].second][j].second});
		}
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	for (int i = 1; i <= n; i++){
		if (eq[i].empty()){
			continue;
		}
		for (int j = 1; j <= n + m; j++){
			f[j] = 100000000000000000;
		}
		q.push({0, i + m});
		f[i + m] = 0;
		while (!q.empty()){
			long long t = q.top().first;
			long long p = q.top().second;
			q.pop();
			if (f[p] < t){
				continue;
			} 
//			cout << t << ' ' << p << '\n';
			for (int j = 0; j < e[p].size(); j++){
				int x = e[p][j].first;
				int ww = e[p][j].second;
//				cout << "----" << x << " " << ww << '\n';
				if (t + ww < f[x]){
					q.push({t + ww, x});
					f[x] = t + ww;
				}
			}
		}
		for (int j = 0; j < eq[i].size(); j++){
			int id = eq[i][j].first;
//			cout << i << " " << id << '\n'; 
			int x = qqq[id].first, y = qqq[id].second;
			if (id > qq){
				id -= qq;
			} 
			ans[id] = min(ans[id], w[x] + eq[i][j].second + f[y] + w[y]);
//			cout << x << ' ' << y << ' ' << w[x] << ' ' << w[y] << ' ' << eq[i][j].second << ' ' << f[y] << '\n';
		}
//		cout << i << '\n';
//		for (int j = 1; j <= n + m; j++){
//			cout << f[j] << ' ';
//		}
//		cout << '\n';
	}
	for (int i = 1; i <= qq; i++){
		cout << ans[i] << '\n';
	}
	return 0;
} 
