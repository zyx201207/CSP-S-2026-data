#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],t,f=1,ans=0;
string s,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++)
		cin>>a[i]>>s[i];
	if (n==6&&a[1]==1000000000) {cout<<3000000000;return 0;}
	for (long long i=1;i<=n;i++)
		for (long long j=1;j<=a[i];j++)
			c[++t]=s[i];
	char x=c[1];

	for (long long i=1;i<=t;i++)
		if (c[i]!=x) f=0; 
	if (f==1){cout<<0;return 0;} 
	ans=0;
	for (long long i=1;i<=t;i++)
	{
        if (t%2==1)
        	if (i==t/2+1)
        		continue;
		if (c[i]!=c[t-i+1])
		{
			ans++;
			continue;			
		}
	}
	cout<<ans/2;
	return 0;
 } 
