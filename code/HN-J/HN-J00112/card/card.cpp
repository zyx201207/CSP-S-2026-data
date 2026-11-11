#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1;

int n, m, a[MAXN], frm[MAXN], la[MAXN], cnt[MAXN], d[MAXN], tot, la2[MAXN], nr[MAXN], maxx[MAXN];
struct node {
	int l, r;
}b[MAXN];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	iota(frm + 1, frm + n + 1, 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int L = n + 1;
	for(int i = n; i >= 1; i--) {
		if(la[a[i]]) {
			L = i;
			frm[i] = frm[la[a[i]]];
			cnt[frm[i]]++;
			la2[i] = la[a[i]];
			b[++tot] = {i, la[a[i]] - 1};
		}
		else {
			cnt[i]++;
		}
		nr[i] = L;
		la[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		if(cnt[i]) { 
//			cout << nr[i] << " " << cnt[i] << "\n"; 
			d[i] += cnt[i], d[nr[i]] -= cnt[i];
			cnt[frm[nr[i]]] += cnt[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		d[i] += d[i - 1];
		maxx[a[i]] = max(maxx[a[i]], d[i]);
//		cout << d[i] << " ";
	}
//	cout << "\n";
	for(int i = 1; i <= m; i++) {
		cout << maxx[i] << " "[i == m];
	}
	return 0;
} 
//Don't you think you had enough already?
//Get back to work, NOW!
