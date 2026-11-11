#include <bits/stdc++.h>
using namespace std;
int n;
long long num;
string s;
int main()
{
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long a;
		char c;
		cin >> a >> c;
		for (int j = 1; j <= a; j++)
		{
			s += c;
		}
	}
	for (int i = 1; i+i <= s.size(); i++)
	{
		if(s[i-1] != s[s.size()-i]) num++;
	}
	cout << num;
	return 0;
}
