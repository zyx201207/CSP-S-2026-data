#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

const int M = 3e5 + 5;

int n, m;

int a[N];

struct section {
	int l, r;
};
section s[N];

int id;

bool cmp (section a, section b) {
	return a.r < b.r;
}
bool exist[N];
int cnt[M];

int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] == a[j]) {
				s[++id] = {i, j};
				break;
			}
		}
	}
	sort (s + 1, s + 1 + id, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			exist[j] = 0;
		}
		int mx = i;
		int ll = 0, rr = mx;
		for (int j = 1; j <= id; j++) {
			if (s[j].l < mx) continue;
			if (s[j].l >= rr) {
				ll = s[j].l;
				rr = s[j].r;
			}
		}
		for (int j = rr; j <= n; j++) {
			if (!exist[a[j]]) cnt[a[j]] ++;
			exist[a[j]] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}
