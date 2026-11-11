#include <bits/stdc++.h>

using namespace std;

long long mj, n, m, d, q, ans[510][510];

struct node1 {
	long long line, na, tim;
	bool book[510] = {};
} dui[500010];

struct node {
	long long line[21] = {}, na[21] = {}, tim[21] = {}, tot = 0, ttt[21] = {}, chuqu;
} a[510];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> mj >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {
		cin >> a[i].chuqu;
	}

	for (int i = 1; i <= n; i++) {
		int k, lana, nal, ti;
		cin >> k >> lana >> ti;

		a[lana].ttt[i] = ti;
		a[lana].tim[a[lana].tot] = ti;
		a[lana].line[a[lana].tot] = i;

		for (int j = 1; j < k; j++) {
			cin >> nal >> ti;

			a[nal].line[a[nal].tot] = i;
			a[nal].na[a[nal].tot] = lana;
			a[nal].tim[a[nal].tot] = ti;
			a[nal].ttt[i] = ti;
			a[nal].tot += 1;

			a[lana].na[a[lana].tot] = nal;
			a[lana].tim[a[lana].tot] = ti;
			a[lana].line[a[lana].tot] = i;
			a[lana].tot += 1;

			lana = nal;
			/*for (int k = 1; k <= m; k++) {
				cout << a[k].tot << "\n";
				for (int l = 0; l < a[k].tot; l++) {
					cout << a[k].line[l] << " " << a[k].na[l] << " " << a[k].tim[l] << "\n";
				}
				cout << "\n";
			}
			cout << "\n\n";*/
		}
	}

	/*for (int k = 1; k <= m; k++) {
		cout << a[k].tot << "\n";
		for (int l = 0; l < a[k].tot; l++) {
			cout << a[k].line[l] << " " << a[k].na[l] << " " << a[k].tim[l] << "\n";
		}
		cout << "\n";
	}*/

	for (int k = 1; k <= m; k++) {
		long long h = 0, t = 0;

		dui[0].line = 0;
		dui[0].tim = 0;
		dui[0].na = k;
		dui[0].book[k] = true;

		while (h <= t) {
//			cout << dui[h].line << " " << dui[h].tim << " " << dui[h].na << "\n";

			long long lana = dui[h].na;

			for (int i = 0; i < a[lana].tot; i++) {
				long long nowna = a[lana].na[i];

				if (nowna != k && !dui[h].book[nowna]) {
					long long ttime;

//					cout << dui[h].line << " " << a[lana].line[i] << '\n';

					if (dui[h].line != a[lana].line[i])
						ttime = dui[h].tim + a[lana].tim[i] + a[lana].ttt[a[lana].line[i]];
					else
						ttime = dui[h].tim + a[lana].tim[i] - a[lana].ttt[a[lana].line[i]];

//					cout << '\t' << a[lana].tim[i] << " " << a[lana].ttt[a[lana].line[i]] << " " << ttime << '\n';

					if (ans[k][nowna] == 0) {
						ans[k][nowna] = ans[nowna][k] = ttime;
					} else {
						ans[k][nowna] = ans[nowna][k] = min(ttime, ans[k][nowna]);
					}

					t += 1;

					dui[t].line = a[lana].line[i];
					dui[t].tim = ttime;
					dui[t].na = nowna;
					for (int j = 0; j < 510; j++)
						dui[t].book[j] = dui[h].book[j];
					dui[t].book[nowna] = true;
				}
			}
//			cout << h << " " << t << "\n";

			h += 1;
		}
//				cout << "\n";
//		for (int i = 1; i <= m; i++) {
//			cout << ans[k][i] << " ";
//		}
//		cout << "\n\n";
	}

	while (q--) {
		long long ll, rr;
		cin >> ll >> rr;
		cout << ans[ll][rr] + a[ll].chuqu + a[rr].chuqu << "\n";
	}

	return 0;
}










