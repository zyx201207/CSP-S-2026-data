#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long n, m, a[500005], sum, ans = 1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++){
		if (m >= (a[i + 1] - a[i]) * i){
			m -= (a[i + 1] - a[i]) * i;
			ans++;
		}
		else break;
	}
	cout << ans;
	return 0;
}
