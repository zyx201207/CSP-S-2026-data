#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
long long n, m, a[N], sum[N], ans;

int main(){
	freopen("crystal.in","r", stdin);
	freopen("crystal.out", "w", stdout);
	memset(a, 0x3f, sizeof(a));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = n; i >= 1; i--){
		if (a[i] != a[i + 1])
			if (a[i] * i - sum[i] <= m){
			    ans = i;
			    break;
			}
	}
	cout << ans;
	return 0;
}
