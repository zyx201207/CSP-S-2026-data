#include<bits/stdc++.h>
using namespace std;
int n,l,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	s += ' ';
	for(int i = 1;i <= n;i++)
	{
		int a;
		char b;
		cin >> a >> b;
		l += a;
		for(int j = 1;j <= a;j++)
		{
			s += b;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(s[i] != s[l+1-i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
