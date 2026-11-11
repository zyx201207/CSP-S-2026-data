#include<bits/stdc++.h>

using namespace std;
int n,a;
long long cc;
string s;
char s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a >> s1;
		for (int i = 0;i < a;i++)
		{
			s = s + s1;
		}
	}
	long long m = (s.size() + 1) / 2;
	for (long long i = 0;i <= m;i++)
	{
		if(s[i] != s[s.size() - i - 1])
		{
			cc++;
		}
	}
	cout << cc;
	return 0;
}
