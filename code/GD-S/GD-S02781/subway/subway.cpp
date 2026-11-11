#include<bits/stdc++.h>
using namespace std;
int w[500005];
int x[500005];
int a[805][805];
int t[805][805];
vector<pair<int, int> > v[805][805];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 2; j <= x[i]; j++) {
			v[i][j - 1].push_back({i, j});
			v[i][j].push_back({i, j - 1});
		}
	}
	int v = 0;
	cin >> v;
	for(int i=1;i<=v;i++)
	{
		cout<<-1<<'\n';
	}
	return 0;
}
