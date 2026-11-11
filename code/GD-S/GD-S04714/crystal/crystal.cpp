#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 10, WZX = 1e12;
int n, m;
ll ans, maxa, mina = WZX;
ll a[MAXN], d[MAXN];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxa = max(maxa, a[i]);
		mina = min(mina, a[i]);
	}
	sort(a + 1, a + n + 1);
	bool flag = 1;
	ll vds;
	if (maxa - mina < m) m = maxa - mina;
	for (int i = 1; i <= n; i++){
		d[i] = a[i] - a[i - 1];
		if (i == 2) vds = d[i];
		else if (i != 1 && d[i] != vds){
//			cout << a[i] << "!" << a[i - 1] << " ";
			flag = 0;
		}
	}
//	for (int i = 1; i <= n; i++) cout << d[i] << " ";
//	cout << '\n';
//	cout << vds << '\n';
	if (!flag){
//		cout << 1 << '\n';
		for (int i = 1; i <= n; i++){
			if (ans > n - i + 1) break;
			ll num = 0, wzx = 0;
			for (int j = i + 1; j <= n; j++){
				if (num > m){
					break;
					ans--;
				}
				num += d[j] * (j - i - 1);
				wzx++; 
			}
			ans = max(ans, wzx);
		}
	}
	else{
//		cout << 2 << '\n';
		for (int i = 1; i <= n; i++){
			if (1ll * i * vds * (i - 1) > 1ll * 2 * m) break;
			ans++;
		}	
	}
	cout << ans;
	return 0;
}
