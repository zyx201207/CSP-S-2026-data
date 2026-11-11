#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s = {};
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin >> a >> c;
		for(int j=1;j<=a;j++)
		{
			s += c;
		}
	}
	long long cnt = 0;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
