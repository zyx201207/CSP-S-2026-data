#include <bits/stdc++.h>
using namespace std;
long long n,ans;
long long a;
string b,s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(long long i=1;i<=a;i++)
		{
			s+=b;
		}
	}
	s1=s;
	reverse(s.begin(),s.end());
	for(long long i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s1[i])
		{
			ans++;
			s1[i]=s[i];
		}
	}
	cout<<ans;
	return 0;
 }

