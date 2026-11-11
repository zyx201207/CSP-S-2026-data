#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n;
int ans = 0;
int lens = 0;
int cnt = 0;

struct N{
	int num = 0;
	char s;
}a[200005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++) {
		int m;
		char c;
		cin >> m >> c;
		lens += m; 
		a[++cnt].s = c;
		a[cnt].num = m;
	}
	int l1 = 0;
	int l2 = 0;
	for(int i=1; i<=cnt; i++) {
		l1 += a[i].num;
		if(l1 == lens / 2) break;
		if(l1 > lens / 2) {
			a[i].num -= (l1 - lens / 2) * 2;
			break;
		}
	}
	int i = 1;
	while(i < cnt) {
		if(a[i].s == a[cnt].s) {
			if(a[i].num < a[cnt].num) {
				a[cnt].num -= a[i].num;
				a[i].num = 0;
				i++;
			}
			else if(a[i].num > a[cnt].num) {
				a[i].num -= a[cnt].num;
				a[cnt].num = 0;
				cnt--;
			}
			else {
				a[i].num = 0;
				a[cnt].num = 0;
				i++;
				cnt--;
			}
		}
		else {
			if(a[i].num < a[cnt].num) {
				a[cnt].num -= a[i].num;
				a[i].num = 0;
				ans += a[cnt].num -= a[i].num;
				i++;
			}
			else if(a[i].num > a[cnt].num) {
				a[i].num -= a[cnt].num;
				a[cnt].num = 0;
				ans += a[i].num -= a[cnt].num;
				cnt--;
			}
			else {
				ans += a[i].num; 
				a[i].num = 0;
				a[cnt].num = 0;
				i++;
				cnt--;
//				cout << ans << endl; 
			}
		}
	}
	cout << ans;
}
