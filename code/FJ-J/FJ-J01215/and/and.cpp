#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
ll n, m, a[N];
bool flag = true, b[N][35], c[35];
void solve_1() { // subtask 1 ~ 5
	ll cnt, num, now, ans = 0;
	for(int p = 0; p < (1 << n); p++) {
		cnt = p, num = 0, now = -1;
		for(int i = 1; i <= n; i++) {
			if(cnt & 1) {
				if(now == -1) now = a[i];
				else now &= a[i];
				num++;
			}
			cnt >>= 1;
		}
		if(num == m) ans = max(ans, now);
	}
	cout << ans;
}
void solve_2() { // subtask 6
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, a[i]);
	cout << ans;
}
void solve_3() { // subtask 7
	ll ans = a[1];
	for(int i = 2; i <= n; i++) ans &= a[i];
	cout << ans;
}
void solve_4() { // subtask 8 ~ 10
	ll ans = 0;
	for(int i = 1; i <= n; i++) 
		for(int j = i + 1; j <= n; j++) 
			ans = max(ans, a[i] & a[j]); 
	cout << ans;
}
void solve_5() { // subtask 13
	ll ans;
	sort(a + 1, a + n + 1, greater<int>());
	ans = a[1];
	for(int i = 2; i <= m; i++) ans &= a[i];
	cout << ans;
}
void solve_6() { // subtask 14, 15
	ll ans = a[n];
	for(int i = 2, j = n - 1; i <= m; i++, j--) ans &= a[j];
	cout << ans;
}
int main() {
	freopen("and.in", "r", stdin); 
	freopen("and.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != i - 1) flag = false;
	}
	if(n <= 20) solve_1();
	else if(n <= 2000) {
		if(m == 1) solve_2();
		else if(m == n) solve_3();
		else solve_4();
	} else if(flag) solve_6();
	else solve_5();
	return 0;
}
