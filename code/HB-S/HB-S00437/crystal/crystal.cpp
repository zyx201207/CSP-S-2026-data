#include<bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for(int i = (a); i <= (b); i++)
#define ro(i, a, b) for(int i = (a); i >= (b); i--)
#define int long long

const int N = 5e5 + 5;


int n, m;
int a[N];



int now;
int q[N], hh = 1, tt = 0;
int ans;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	fo(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	fo(i, 1, n) {
		q[++tt] = a[i];
		now += (a[i] - a[i - 1]) * (tt - hh);
		while(hh < tt && now > m) {
			now -= a[i] - q[hh++];
		}
		ans = max(ans, tt - hh + 1);
	}
	cout << ans;
	return 0;
}
/*
5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
