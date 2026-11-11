#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];
long long pre[500005]; 
long long lst[500005];
long long sum[500006];
long long cf[500005];
bool vis[5000005];
long long ans[500005];
long long l[500005], r[500005], cnt;

bool check() {
	bool f = 1;
	for (int i = 2; i <= n; i++) if (a[i-1] > a[i]) return false;
	return true;
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (check()) {
		for (int i = 2; i <= n; i++) {
			if (a[i] != a[i-1]) {
				ans[a[i-1]] = i-1;
			}
		}
		ans[a[n]] = n;
		for (int i = 1; i <= m; i++) cout << ans[i] << " ";
		return 0;
	} 
	
	for (long long i = 1; i<= n; i++) {
		if (!pre[a[i]]) {
			pre[a[i]] = i;
		}
		lst[a[i]] = i;
	}
	for (long long i = 1; i <= m; i++) {
		cf[pre[i]]++;
		cf[lst[i]]--;
//		cout << i << " : " <<pre[i] << " " << lst[i] << endl;
	}
	sum[0] = 0;
	for (long long i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + cf[i];
		vis[i] = sum[i];
//		cout << sum[i] << endl;
	}
	
	for (long long i = 1; i <= n; i++) {
		if (!vis[i]) ans[a[i]] = i;
		else ans[a[i]]++;
	}
	for (long long i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}

/*
4 3
1 2 1 3


*/
