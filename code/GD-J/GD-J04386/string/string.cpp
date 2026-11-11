#include <bits/stdc++.h>
using namespace std;

#define int long long //hhhhhhhhhhh 
const int N = 2e5 + 10;
int a[N], n;
char c[N];
bool ts(char c[])
{
	for (int i = 2; i <= n; i++)
	{
		if (c[i] != c[i-1])
			return false;
	}
	return true;
}
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	cin >> a[1] >> c[1];
	int num = a[1], maxn = 0;
	for (int i = 2; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		num = gcd(num, a[i]);
		maxn = max(maxn, a[i]);
	}
	if (ts(c) || n == 1) 
	{
		cout << 0 << endl;
		return 0;
	}
	else if (n == 2)
	{
		cout << min(a[1], a[2]) << endl;
		return 0;
	}
	else if (n <= 2000 && maxn <= 50)
	{
		string s = "";
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= a[i]; j++)
				s += c[i];
		}
		int l = s.size(), ans = 0;
		for (int i = 0; i < l/2; i++)
		{
			int ttt = l-1-i;
			if (s[i] != s[ttt]) 
			{
				s[ttt] = s[i];
				ans++;
			}
		}
		cout << ans << endl;
		return 0;			
	}		
	int t = 1ll * maxn / num * n;
	if (t <= 1e9)
	{
		int ans = 0;
		string s;
		for (int i = 1; i <= n; i++)
		{
			int mc = a[i] / num;
			for (int j = 1; j <= mc; j++) s += c[i];
		}
		int l = s.size();
		//cout << s << endl; 
		for (int i = 0; i < l/2; i++)
		{
			int ttt = l-1-i;
			//cout << s[0] << " " << s[ttt] << endl;
			if (s[i] != s[ttt]) 
			{
				//cout << s[i] << " " << s[l+i-1] << endl;
				s[ttt] = s[i];
				ans += num;
			}
		}
		//cout << s << endl;
		cout << ans << endl;
		return 0;
	}
	else
	{
		string s = "";
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= a[i]; j++)
				s += c[i];
		}
		int l = s.size(), ans = 0;
		for (int i = 0; i < l/2; i++)
		{
			int ttt = l-1-i;
			if (s[i] != s[ttt]) 
			{
				s[ttt] = s[i];
				ans++;
			}
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}
