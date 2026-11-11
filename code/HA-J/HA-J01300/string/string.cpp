#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string s1="";
	for(long long i=0;i<n;i++)
	{
		long long a;
		string b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++)
		{
			s1+=b;
		}
	}
	string s2="";
	long long ans=0;
	for(long long i=s1.size()-1;i>=0;i--)
	{
		s2+=s1[i];
	}
	for(long long i=0;i<=(s1.size()-1)/2;i++)
	{
		if(s1[i]!=s2[i])
		{
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
