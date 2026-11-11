#include <bits/stdc++.h>
using namespace std;

int n, len = 0;
long long ans = 0;
string s = " ";
int a[200005];
long long na[500005];
char c[200005], nc[500005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i] >> c[i];
		len += c[i];
	}
	
	if (len <= 1e6)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= a[i]; j++) s += c[i];
		
		for (int i = 1; i <= len / 2; i++)
		{
			int j = len - i + 1;
			ans += (s[i] != s[j]);
		}
		cout << ans << endl;
	}
	else
	{
		bool flag = true;
		for (int i = 1; i <= n; i++) na[i] = na[i - 1] + a[i];
		long long p = 0;
		for (int i = n; i >= 2; i--) 
		{
			p += a[i];
			na[n * 2 - i + 1] = p;
		}
		
		sort(na + 1, na + 2 * n - 1 + 1);
		
		int lst = 0;
		long long sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += a[i];
			for (int j = lst + 1; na[j] <= sum && j <= 2 * n - 1; j++) nc[j] = c[i], lst = j;
		}
		
		for (int i = 1; i <= n - 1; i++)
		{
			int j = 2 * n - i;
			if (nc[i] != nc[j]) ans += na[i] - na[i - 1];
		}
		
		cout << ans << endl;
	}
	return 0;
}


