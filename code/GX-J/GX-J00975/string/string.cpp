#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
string s,l,r;
long long a,b,n,ans;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b;
		cin>>c;
		for(int j=1;j<=b;j++)
		{
			s+=c;
		}
		n+=b;
	}
	if(!n%2)
	{
		for(int i=0;i<n/2;i++)
		{
			l+=s[i];
		}
		for(int i=n/2;i<n;i++)
		{
			r+=s[i];
		}
	}
	else if(n%2)
	{
		for(int i=0;i<n/2;i++)
		{
			l+=s[i];
		}
		for(int i=n/2+1;i<n;i++)
		{
			r+=s[i];
		}
	}
	for(int i=0;i<=n/2+1;i++)
	{
		if(l[i]!=r[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
