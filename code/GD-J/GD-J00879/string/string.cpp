#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
bool bk = 0;
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, ans = 0, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int l; char c;
		cin >> l >> c;
		int cnt = 1;
		for (int i = cnt; i <= cnt + l - 1; ++i) a[i] = (int)c;
		cnt += l;
		ans += l;
	}
	for (int i = 1; i <= ans; ++i)
	{
		int cnt = 0;
		if (ans % 2 == 0) 
		{
			cnt = ans;	
			if (a[i] == a[cnt]) bk = 1, cnt = cnt - 1;
			else if (a[i] != a[cnt])
			{
				bk = 0; 
				break;
			}
		}
		else if (ans % 2 == 1) 
		{
			cnt = ans;
			if (i == cnt) break;
			else if (a[i] == a[cnt]) bk = 1, cnt = cnt - 1;
			else if (a[i] != a[cnt])
			{
				bk = 0; 
				break;
			}
		}
	}
	if (bk == 1) 
	{
		cout << 0;
		return 0;
	}
	else if (bk == 0)
	{
		int len = 0, cnt = ans;
		if (ans % 2 == 0) len = ans / 2;
		else if (ans % 2 == 1) len = (ans + 1) / 2 - 1;
		for (int i = 1; i <= len; ++i) {if (a[i] != a[cnt]) cnt--, sum++; else if (a[i] == a[cnt]) cnt--;}
	}
	cout << sum;
	return 0;
}
