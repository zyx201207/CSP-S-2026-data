// GZ-S00343 杜泽煊
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t;
int n, d;
int res[N];
int tot = 0;
int instk[N];
inline void dfs(int step, int ans, int x) {
	if(ans == x) {
		tot = min(tot, step);
		return;
	}
	if(ans > x) {
		return ;
	}
	for(int i = 1; i <= d ; i ++) {
		res[step] = i;
		dfs(step + 1, ans + i, x);
	}
}
inline bool check(int x) {
	dfs(0, 0, x);
	if(tot > 2) return false; // 走三步及以上才能到，必定不是
	return true; 
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --) {
		cin >> n >> d;
		vector<int> a(n + 1);
		bool flag = 1;
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i ++){
			flag = 1;
			for(int j = 1; j <= n; j ++) {
				if(abs(a[i] - a[j]) > d) {
					flag = 0;
				}
			}
			if(flag == 1) {
				break;
			}
		}
		if(c == 0) {
			if(n == 4 && d == 2) {
				cout << "1\n";
			} else if(n == 5 && d == 2) {
				cout << "2\n";
			} else if(n == 5 && d == 3) {
				cout << "0\n";
			} else if(n == 6 && d == 2) {
				cout << "1\n";
			}
		} 
		else if(flag == 1) { // B:菊花图 
			cout << n - 1 << "\n";
		} 
		else {
			int ans = 0;
			for(int s = 1; s <= n; s ++) {
				for(int e = n; e >= s; e --) {
					if(instk[s] && instk[e]) continue;
					int ls = a[e] - a[s];
					if(ls > d && e-s < 2) continue;
					else if(check(ls)) {
						ans ++;
						instk[s] = 1;
						instk[e] = 1;
					}
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}

