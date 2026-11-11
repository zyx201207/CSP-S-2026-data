#include <bits/stdc++.h>

using namespace std;

string s = "",s1 = "",s2 = "";
vector<long long> dp[10005] = {{}};

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	int n;
	char c;
	cin >> n;
	while (n--)
	{
		cin >> a >> c;
		while (a--)
		{
			s += c;
		}
	}
	int l = s.size();
	for (int i = 0;i < l / 2;i++)
	{
		s1 += s[i];
		s2 += s[l - i - 1];
	}
	int l1 = s1.size(),l2 = s2.size();
	for (int i = 1;i <= l1;i++)
	{
		for (int j = 1;j <= l2;j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
			}
		}
	}
	cout << l1 - dp[l1][l2];
	return 0;
}
