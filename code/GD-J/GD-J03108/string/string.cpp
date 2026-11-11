#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5; 
int n, a[N], cnt, t;
char c[N];
string s;
signed main ()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		if (i == 1)t = a[i];
		else t = __gcd(t, a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] /= t;
		for (int j = 1; j <= a[i]; j++)
		{
			s += c[i];
		}
	}
	//cout << t << '\n' << s << '\n';
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])cnt++;
	}
	cout << cnt * t;
	return 0;
}
/*

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

aabaca




*/

