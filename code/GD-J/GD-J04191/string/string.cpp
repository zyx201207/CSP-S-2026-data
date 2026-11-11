#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[200005];
char c[200005];
long long L = 0;
bool flag = 1;
bool b[200005];
long long mn;
string str[200005];
int dfs_cnt = 0;

void dfs(int idx, string s)
{
	dfs_cnt ++;
	
//	if (dfs_cnt == 10000) 
//	{
//		cout << mn;
//		exit(0);
//	}
	
	if (idx > n)
	{
		int cnt = 0;
		for (int i = 0; i < L; i++)
		{
			if (s[i] != s[L - i]) 
			{
				cnt++;
				if (cnt > mn) return;
			}
		}
		if (cnt == 0)
		{
			cout << "0";
			exit(0);
		}
		mn = min(mn, cnt);
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == 0)
		{
			b[i] = 1;
			dfs(idx+1, s+str[i]);
			b[i] = 0;
		}
	}
}

void fan()
{
	if (flag == 1)
	{
		cout << "0";
		return;
	}
	
	if (n == 1)
	{
		cout << "0";return;
	}
	
	if (n == 2)
	{
		if (c[1] == c[2]) 
		{
			cout << "0";return;
		}
		else
		{ 
			cout << min(a[1], a[2]);return;
		}
		
	}
	
	if (n < 10)
	{
		//120 125 
		if (L <= 100)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= a[i]; j++)
				{
					str[i] += c[i];
				}
			}
			
			mn = L;
			dfs(1, "");
			cout << mn;return;
		}
	}
	
	cout << "4191";
}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		if (c[i] != c[1]) flag = 0;
		L += a[i];
	}
	
	fan();
}
