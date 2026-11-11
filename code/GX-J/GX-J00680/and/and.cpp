#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+10;
ll a[N];
bool cmp(int x, int y){
	return x > y;
}
int two[N],x[N];
int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	int cnt = 1;
	bool flag=true;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		memset(two, 0, sizeof(two));
		cnt = 1;
		while (a[i] != 0) {
			int y = a[i] % 2;
			a[i] /= 2;
			two[cnt] = y;
			cnt++;
		}
		for (int i = cnt - 1; i >= 1; i--) {
			if (flag == true) {
				x[i]=two[i];
			}
			flag=false;
		}
		for (int i = cnt - 1; i >= 1; i--) {
			if (x[i] != two[i]){
				ans++;
			}
		}	
	}
	if (m == 1) {
		sort(a + 1,a + n + 1, cmp);
		cout << a[1];
		return 0;
	} else {
		cout << ans;
	}
	return 0;
}
