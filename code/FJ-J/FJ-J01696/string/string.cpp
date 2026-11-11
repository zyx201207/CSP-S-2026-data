#include <bits/stdc++.h>
using namespace std;
int n,num;
long long a;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		for (long long j = 1;j <= a;j++)
		{
			s += c;
		}
	}
	int l = s.length();
	for (int i = 0;i <= l / 2 - 1;i++)
	{
		if (s[i] != s[l - i - 1])
		{
			num++;
		}
	}
	cout << num;
	return 0;
} 
