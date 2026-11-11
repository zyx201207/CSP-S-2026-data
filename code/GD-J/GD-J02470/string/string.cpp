#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int x;
		string m;
		cin >> x >> m;
		for(int j=1;j<=x;j++)
		{
			s+=m;
		}
	}
	for(int i=0;i<=s.length()/2;i++)
	{
		if(s[i]!=s[s.length()-1-i])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
