#include <bits/stdc++.h>

using namespace std;

#define int long long

struct abab{
	int a;
	char c;
}; 

string s;
int n, cnt = 0, ans;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		abab tmp;
		cin >> tmp.a >> tmp.c;
		for (int j = cnt; j < cnt + tmp.a; ++j)
		{
			s += tmp.c;
		}
		cnt += tmp.a;
	}
	
	for (int i = 1; i <= cnt / 2; ++i)
	{
		if (s[i] != s[cnt - i + 1])
		{
			ans ++;
		}
	}
	cout << ans << "\n";
}
