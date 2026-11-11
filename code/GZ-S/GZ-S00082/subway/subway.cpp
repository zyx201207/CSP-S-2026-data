//GZ-S00082 贵阳市第一实验中学 姚彦竹
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
constexpr const char* el = "\n";
int c, n, m, d, q, w[(ull)5e5+10], k, st[(ull)1e5], ed[(ull)1e5], tmp_a, tmp_b;
vector<int> a[505], t[505];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> tmp_a >> tmp_b;
			a[i].push_back(tmp_a);
			t[i].push_back(tmp_b);
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> st[i] >> ed[i];
	}
	
	return 0;
}
