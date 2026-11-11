#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010], t1_max;
bool vis[30];
void dfs(int mask, int ans, int now) {
	if(now == m) {
		t1_max = max(t1_max, ans);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) {
			continue;
		}
		vis[i] = 1;
		int k = ans & a[i];
		dfs(mask | (1 << i), k, now + 1);
		vis[i] = 0;
	}
}
bool cmp(int qwq, int wac) {
	return qwq > wac;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >>n >>m;
	int k = 0, maxai = 0, cnt[110] = { };
	for(int i = 1; i <= n; i++) {
		cin >>a[i];
		if(i <= 25) {
			k += (1 << i);
		}
		maxai = max(maxai, a[i]);
		if(a[i] == 0) cnt[0]++;
		if(a[i] == 1) cnt[1]++;
		if(a[i] == 2) cnt[2]++;
		if(a[i] == 3) cnt[3]++;
	}
	k += 1;
	if(n <= 20) {
		dfs(0, k, 0);
		cout <<t1_max;
		return 0;
	}
	if(m == 1) {
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
		}
		cout <<ans;
		return 0;
	}
	if(m == n) {
		int ans = a[1];
		for(int i = 2; i <= n; i++) {
			ans = ans & a[i];
		}
		cout <<ans;
		return 0;
	}
	if(m == 2) {
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout <<ans;
		return 0;
	}
	if(m == n - 1) {
		int f[40] = { };
		for(int i = 1; i <= n; i++) {
			int pri = 1, k = a[i];
			while(k) {
				if(k & 1) {
					f[pri]++;
				}
				k >>= 1;
				pri++;
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			int pri = 1, k = a[i];
			while(k) {
				if(k & 1) {
					f[pri]--;
				}
				k >>= 1;
				pri++;
			}
			int qwq = 0;
			for(int j = 1; j <= 35; j++) {
				if(f[j] == n - 1) {
					qwq += (1 << (j - 1));
				}
			}
			ans = max(ans, qwq);
			k = a[i], pri = 1;
			while(k) {
				if(k & 1) {
					f[pri]++;
				}
				k >>= 1;
				pri++;
			}
		}
		cout <<ans;
		return 0;
	}
	if(maxai < 4) {
		if(cnt[3] >= m) cout <<3;
		else if(cnt[3] + cnt[2] >= m) cout <<2;
		else if(cnt[3] + cnt[1] >= m) cout <<1;
		else cout <<0;
		return 0;
	}
	else {
		sort(a + 1, a + n + 1, cmp);
		int ans = 0;
		for(int i = 1; i <= n; ) {
			int sum = 0;
			for(int j = i; a[i] == a[j]; j++) {
				sum++;
				i = j;
			}
			i += 1;
			if(sum >= m) {
				ans = max(ans, a[i-1]);
			}
		}
		cout <<ans;
		return 0;
	}
}
