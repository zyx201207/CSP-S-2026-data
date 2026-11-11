#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k0;
long long w[500005], dis[505][505];
vector<int> v[500005];
vector<long long> l[500005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k0;
		for(int j = 1;j <= k0;j++){
			cin >> c >> d;
			v[c].push_back(i);
			l[c].push_back(d);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)
			dis[i][j] = 0x3f3f3f3f3f3f3fll;
		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;i++){
		int sz = v[i].size();
		for(int j = 0;j < sz;j++){
			for(int k = j + 1;k < sz;k++){
				dis[v[i][j]][v[i][k]] = min(dis[v[i][j]][v[i][k]], l[i][j] + l[i][k]);
				dis[v[i][k]][v[i][j]] = dis[v[i][j]][v[i][k]];
			}
		}
	}
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--){
		cin >> c >> d;
		int sz1 = v[c].size(), sz2 = v[d].size();
		long long ans = 0x3f3f3f3f3f3fll;
		for(int i = 0;i < sz1;i++)
			for(int j = 0;j < sz2;j++)
				ans = min(ans, l[c][i] + l[d][j] + dis[v[c][i]][v[d][j]]);
		ans += w[c] + w[d];
		cout << ans << endl;
	}
	return 0;
}
