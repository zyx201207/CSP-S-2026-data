#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, j = 1, sum, ans;
long long m, a[N], s[N], now, t[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
//	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
//	cout << endl;
	for(int i = 1; i < n; i++) s[i] = a[i + 1] - a[i]/*, cout << s[i] << ' '*/;
//	cout << endl;
	for(int i = 1; i < n; i++) t[i] = t[i - 1] + s[i]/*, cout << t[i] << ' '*/;
//	cout << endl;
	for(int i = 1; i < n; i++){
		now += (i - j + 1) * s[i];
		sum++;
		while(now > m && j < i){
			//cout << i << ' ' << j << ' ' << now << '\n';
			now = now - t[i] + t[j - 1];
			sum--;
			j++;
		}
		ans = max(sum, ans);
	}
	cout << ans + 1 << endl;
	return 0;
}
