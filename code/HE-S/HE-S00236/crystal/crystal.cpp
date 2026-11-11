#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m;
const ll maxn = 5 * 1e5 + 10;
ll a[maxn];
ll cnt;
ll num;
//Oct31==Dec25?
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	cnt = 1;
	while (m >= 0) {
		if ((a[cnt+1] - a[cnt]) * cnt <= m) {
			m -= (a[cnt+1] - a[cnt]) * cnt;
		}
		else {
			break;
		}
		cnt++;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
