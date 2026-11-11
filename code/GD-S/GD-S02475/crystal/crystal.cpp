#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, edans;
int eny[500006];
map<int, int> mp, st;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	bool Aflag = true, Bflag = true;
	for (int i = 1; i <= n; i++) {
		cin >> eny[i];
		if (eny[i] != i) Aflag = false;
		if (i > 2 && eny[i] - eny[i - 1] != eny[i - 1] - eny[i - 2])
			Bflag = false;
		if (!mp.count(eny[i]))
			st[eny[i]] = i;
		mp[eny[i]]++;
	}
	if (Aflag) {
		for (int i = 1; i <= n; i++)
			if (i * (i - 1) <= 2 * m)
				edans = i;
		cout << edans;
		return 0;
	}
	if (Bflag) {
		int d = eny[2] - eny[1];
		for (int i = 1; i <= n; i++)
			if (i * (i - 1) * d <= 2 * m)
				edans = i;
		cout << edans;
		return 0;
	}
	sort(eny + 1, eny + n + 1);
	eny[n + 1] = eny[n] + 1;
	for (int i = 1; i <= n; i++) {
		if (eny[i] == eny[i + 1])
			continue;
		int res = mp[eny[i]], cst = 0;
		for (int j = st[eny[i]] - 1; j >= 1; j--) {
			if (cst + eny[i] - eny[j] <= m)
				cst += eny[i] - eny[j], res++;
			else
				break;
		}
		edans = max(edans, res);
	}
	cout << edans;
	return 0; 
}
