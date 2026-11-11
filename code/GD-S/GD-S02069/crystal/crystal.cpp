#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
constexpr int N = 5e5+5;
int a[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1,a + n + 1);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] * (i - 1) - sum > m) return cout << i - 1 << endl,0;
		sum += a[i];
	}
	return 0;
}
