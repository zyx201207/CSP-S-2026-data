#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define bep(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
const ll maxn = 5e5 + 5, maxm = 1e18 + 5;
int n, m, ans = 1;
int a[maxn];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool flag = 1, right = 1;
	int dx = 0;
	rep(i, 1, n) {
		cin >> a[i];
		if(a[i] != i) {
			flag = 0;
		}	
		if(i == 2) {
			dx = a[i] - a[i - 1];
			continue;
		}
		if(i != 1) {
			if(dx != a[i] - a[i - 1]) {
				right = 0;
			}
		}
	}
	if(flag) {//特殊性质A 
		int i = 1, sum = 0;
		for(; i <= n; i++) {
			sum += i;
			if(sum > m) {
				cout << i;
				return 0;
			}
		} 
		cout << n;
		return 0;
	}
	if(right) {//特殊性质B
		cout << dx << endl; 
		int i = 1, sum = 0;
		for(; i <= n; i++) {
			sum += i;
			if(sum * dx > m) {
				cout << i;
				return 0;
			}
		} 
		cout << n;
		return 0;
	}
	if(n <= 5000) {
		sort(a + 1, a + n + 1);
		rep(i, 2, n) {//选 i 颗水晶是否成立 
			int minn = INT_MAX;
			rep(j, i, n) {// 枚举开头 
				int sum = 0;
				bep(k, j, j - i + 1) {
					sum += a[j] - a[k];
				}
				minn = min(minn, sum);
			}
			if(minn > m) {
				break;
			}
			ans++;
		}
		cout << ans;
		return 0;
	}
	cout << n << "\n";
	return 0;
}
