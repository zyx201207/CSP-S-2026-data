#include<bits/stdc++.h>
using namespace std;
string s;
long long t,c1,n,ans;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>t>>c;
		for(long long j=1;j<=t;j++)
		{
			c1++;
			s[c1]=c;
		}
	}
	for(long long i=1;i<=c1/2;i++)
	{
		if(s[i]!=s[c1-i+1])
			ans++;
	}
	cout<<ans;
	return 0;
}
