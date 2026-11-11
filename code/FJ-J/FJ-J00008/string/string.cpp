#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	string s = "",t = "";
	cin >> n;
	for (long long i = 1;i <= n;i++)
	{
		long long a;
		char c;
		cin >> a >> c;
		for (long long i = 1;i <= a;i++)
		{
			s = s + c;
		}
	}
	for (long long i = s.size()-1;i >= 0;i--)
	{
		t += s[i];
	}
	for (long long i = 0;i < s.size();i++)
	{
		if (s[i] != t[i]) cnt++;
	}
	cout << cnt / 2;
	return 0;
}
