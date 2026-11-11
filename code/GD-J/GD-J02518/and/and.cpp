#include <bits/stdc++.h>
using namespace std;
struct num{
	long long ten, two;
}a[200002];
long long n, x, ans, m, result;
bool cmp(num x, num y){
	return x.two >= y.two;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i].ten;
		x = a[i].ten;
		result = 0;
		while (x > 0){
			result += (x % 2);
			x /= 2;
		}
		a[i].two = result;
	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1].ten;
	for (int i = 2; i <= m; i++)
		ans &= a[i].ten;
	cout << ans;
	return 0;

}
