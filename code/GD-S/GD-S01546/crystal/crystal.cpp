#include <bits/stdc++.h>
using namespace std;
#define int long long
#define up(i, a, b) for(int i = a; i <= b; i++)
#define dn(i, a, b) for(int i = a; i >= b; i--)
#define VI vector <int>
int ans = 0;
VI pre;
int check(int sts, int n, int m, int i) {
	int l = 0, r = i + 1, mid = (l + r) / 2, siz = i - mid + 1;
	while (l < r) {
		mid = (l + r) / 2;
		siz = i - mid + 1;
		if (sts * siz - (pre[i] - pre[mid - 1]) > m) {
			l = mid + 1;
		}
		else r = mid;
		//cout << i;
	}
	siz = i - r + 1;
	return siz;
}
void sub2(int n, int m) {
	VI a(n + 1);
	up (i, 1, n) cin >> a[i];
	pre.resize(n + 2, 0);
	pre[0] = 0;
	sort(a.begin() + 1, a.end());
	up (i, 1, n) pre[i] = pre[i - 1] + a[i];
	up (i, 1, n) {
		int sts = a[i];
		int cnt = check(sts, n, m, i);
		ans = max(ans, cnt);
	}
	cout  << ans;
	return;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m; cin >> n >> m;
	//sub1(n, m);
	sub2(n, m);
	return 0;
}

/*
void sub1(int n, int m) {
	VI a(n + 1);
	up (i, 1, n) cin >> a[i];
	sort (a.begin() + 1, a.end());
	up (i, 1, n) {
		int sts = a[i];
		int cnt = 0, re = m;
		dn (j, i, 1) {
			int cha = abs(sts - a[j]);
			if (cha <= re) {
				re -= cha;
				cnt++;
			}
			else {
				//cout << a[i] << endl;
				break;
			}
		}
		ans = max(ans, cnt);
 	}
 	cout << ans;
 	return;
}
*/
