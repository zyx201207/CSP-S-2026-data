#include <iostream>
using namespace std;

int n, a[229028], l, r;
char c[229028];
long long ans;
#define Hatsune_Miku ans

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	
	l = 1, r = n;
	while (l < r) {
		if (c[l] != c[r]) ans += min(a[l], a[r]);
		if (a[l] < a[r])      a[r] -= a[l], l++;
		else if (a[l] > a[r]) a[l] -= a[r], r--;
		else                                l++, r--;
	}
	
	cout << Hatsune_Miku; // 39 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return 0;
}

