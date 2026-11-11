#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2E5+5;
int n, a[MAXN];
int sum, ans;
//统计每一个位置修改字母的最佳答案 
char ch[MAXN];

signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> ch[i];
		sum += a[i];
	}
	
	for (int i = 1, j = n; i <= j; ) {
		if (ch[i] == ch[j]) {
			if (a[i] > a[j]) {
				a[i] -= a[j];
				a[j] = 0;
				j --;
			}
			else {
				a[i] = 0;
				a[j] -= a[i];
				i ++;
			}
		} else {
			if (a[i] > a[j]) {
				ans += a[j];
				a[i] -= a[j];
				a[j] = 0;
				j --;
			}
			else {
				ans += a[i];
				a[i] = 0;
				a[j] -= a[i];
				i ++;
			}
		}
	} 
	cout << ans;
	
	return 0;
}
