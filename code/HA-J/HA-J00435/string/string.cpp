#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m = 0;
	string s ="";
	cin >> n;
	string c;
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		cin >> c;
		for (int j = 1;j <= k;j++)
		{
			s += c;
		}
	}
	int x = 0,y = s.size() - 1;
	int ans = 0;
	for (int i = 1;i < s.size();i++)
	{
		if(x >= y)
		{
			break;
		}
		if (s[x] != s[y])
		{
			ans += 1;
		}
		x++;
		y--;
	}
	cout << ans;
}
