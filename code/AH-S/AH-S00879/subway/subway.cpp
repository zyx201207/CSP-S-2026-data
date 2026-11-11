#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10, N = 5e2 + 10;
long long c, n, m, d, q;
long long w[N], k[N], aa[N], bb[N];
struct S {
	long long co;
	long long number;
}st1, st2, st;
vector <S> a[N];
vector <S> weight[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	bool flagA = true;
	long long sumki = 0;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		sumki += k[i];
		if(k[i] > 2) { 
			flagA = false;
		}
		for (int j = 1; j <= k[i]; j++) {
			cin >> aa[j] >> bb[j];
			S st;
			st.number = aa[j];
			st.co = bb[j];
			a[i].push_back(st);
		}
	}
	if(flagA) {
		for (int i = 1; i <= n; i++) {
			if(k[i] == 2) {
				S aaa = a[i][0], bbb = a[i][1];
				S st1, st2;
				st1.number = bbb.number;
				st1.co = st2.co = bbb.co + aaa.co;
				st2.number = aaa.number;
				weight[aaa.number].push_back(st1);
				weight[bbb.number].push_back(st2);
			}
		}
		while(q--) {
			long long x, y;
			cin >> x >> y;
			long long ans = w[x] + w[y];
			cout << ans << "\n";
		}
		return 0;
	}
	while(q--) {
		long long x, y;
		cin >> x >> y;
		cout << w[x] << " " << w[y] << "\n";
	}
	return 0;
}
