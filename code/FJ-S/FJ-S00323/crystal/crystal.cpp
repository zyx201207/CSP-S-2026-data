#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];
//long long tmpa[500005];
int mx = 0;
bool vis[500005];



int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);

	/*
	unsigned long long cnt1;
	for (int i = 1; i < n; i++) {
		int tm = m;
		for (int j = 0; j < i; j++) {
			if (a[i] - a[j] > tm) {
				continue;
			} else {
				tm -= (a[i] - a[j]);
				cnt1++;
			}

		}
		mx = max(mx, cnt1);
		cnt1 = 0;
	}
	*/
	struct Changes {
		int ind;
		long long oriC;
	};
	vector <Changes> changes;
	
	int tm = m;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if ((a[i] - a[j]) > tm || j == i) {
				mx = max(mx, j + 1);
				break;
			}
			if (a[i] > a[j]) {
				changes.push_back({j, a[j]});
				tm -= (a[i] - a[j]);
				a[j] = a[i];
			}
		}
	}

	for (int k = 0; k < changes.size(); k++) {
		a[changes[k].ind] = changes[k].oriC;
	}

	cout << mx;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
