#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; i++)
	{
		int p; cin >> p;
		if(p == 2 || p == 4 || p == 8 || p == 16 || p == 32 || p == 64 || p == 128 || p == 256 || p == 512 || p == 1024 || p == 2048 || p == 4096 || p == 8192 || p == 16384 || p == 32768 || p == 65536 || p == 131072 || p == 262144 || p == 524288 || p == 1048576 || p == 2097152 || p == 4194304 || p == 8388608 || p == 16777216 || p == 33554432 || p == 67108864 || p == 134217728 || p == 268435456 || p == 536870912 || p == 1073741824) continue;
		else a[i] = p;
	}
	sort(a.begin(), a.end());
	ll ans = a[n];
	for(int i = n - 1; i > n - m; i--) ans &= a[i];
	cout << ans;
	return 0;
}
//I totally took a guess but this passed?! %%%
