#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[200200], ans;
char c[200200];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int s = 1, t = n;
	while(s < t) {
		int tmp = min(a[s], a[t]);
		if(c[s] != c[t]) ans += tmp;
		a[s] -= tmp;
		a[t] -= tmp;
		if(a[s] == 0) s++;
		if(a[t] == 0) t--;
	}
	cout << ans << '\n';

	return 0;
}
