#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N = 2e5 + 5;
int n, m, ans = -1, a[N], vis[N];
string s[N];
string zh(int x)
{
	string ss = "";
	while(x)
	{
		ss = ss + char(x % 2 + '0');
		x /= 2;
	}
	reverse(ss.begin(), ss.end());
	return ss;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	IOS;
	cin >> n >> m;
	int maxa = 0, maxi = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = zh(a[i]);
		if(maxa < a[i])
			maxa = a[i], maxi = i;
	}
	int len = (int)s[maxi].size();
	for(int i = 1; i <= n; i++)
	{
		if((int)s[i].size() < len)
		{
			for(int j = 1; j <= len - (int)s[i].size(); j++)
				s[i] = '0' + s[i];
		}
	}
	for(int i = 0; i < len; i++)
	{
		vector<int> ai;
		for(int j = 1; j <= n; j++)
		{
			if(vis[j] == i)
			{
				string t = s[j];
				if(t[i] == '1')
					ai.push_back(j);
			}
		}
		if((int)ai.size() >= m)
		{
			for(int j = 0; j < (int)ai.size(); j++)
				vis[ai[j]]++;
		}
		else
		{
			for(int j = 1; j <= n; j++)
			{
				if(vis[j] == i)
					vis[j]++;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == len)
		{
			if(ans == -1) ans = a[i];
			else ans &= a[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
//luogu uid:1117683
