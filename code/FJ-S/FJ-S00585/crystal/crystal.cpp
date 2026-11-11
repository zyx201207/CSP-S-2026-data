#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	int sum = 0;
	int maxn = INT_MIN;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		maxn = max(a[i], maxn);
		sum += a[i];
	}
	sort(a+1, a+n+1);
	int mid = (a[1] + a[n]) / 2;
	if (m >= maxn * n - sum) cout << n;
	else if (m >= n && m / mid + 2 < n) cout << m / mid + 2;
	else if (m >= n && m / mid + 2 > n) cout << m / mid;
	else cout << 1; 
	return 0;
}
//特殊性质 A：对于所有 i (1 ≤ i ≤ n)，均有 ai = i. --> 15分.
//特殊性质 B：a1, a2, . . . , an 构成等差数列. --> 15分.


//666，真不知道 CSP-S 为什么要出得比 CSP-J 难那么多，何意味？
//这么喜欢合成水晶是吧！C++.
