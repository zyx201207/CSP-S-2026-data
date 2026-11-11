#include <bits/stdc++.h>
using namespace std;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin>>n;
	for(long long i =1;i<=n;i++)
	{
		int m;
		cin>>m;
		string x;
		cin>>x;
		for(int j = 1;j<=m;j++)
		{
			s = s+x;
		}
	}
	long long ans = 0;	
	long long m = s.length()/2;
	for(long long i = 0;i<m;i++)
	{
			if(s[i]!=s[s.length()-i-1]) ans++;
	}
	cout<<ans;
	return 0;

}
