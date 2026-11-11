#include <bits/stdc++.h>
using namespace std;
string s,m;
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	long long n,x;
	cin >> n;
	char a;
	for (int i = 1;i <= n;i++)
	{
		cin >> x;
		cin >> a;
		for (int i = 1;i <= x;i++)
		{
			s += a;
		}
	}
	for (int i = s.length()-1;i >= 0;i--)
	{
		m[s.length()-i-1] = s[i];
	}
	int num;
	int sum = s.length();
	for (int j = 0;j <= s.length()-1;j++)
	{
		if (m[j] == s[j])
		{
			num++;
		}
	}
	if (num == sum)
	{
		cout << 0;
	}
	return 0;
}
