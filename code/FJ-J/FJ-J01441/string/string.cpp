#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0,m=0;
	string s;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		long long x;
		string a;
		cin>>x>>a;
		l+=x;
		for(long long j=1;j<=x;j++) s+=a;
	}
	if(l%2==1)
	{
		for(long long i=0;i<(l-1)/2;i++)
		{
			if(s[i]!=s[l-i-1]) m++;
		}
	}
	else
	{
		for(long long i=0;i<l/2;i++)
		{
			if(s[i]!=s[l-i-1]) m++;
		}
	}
	cout<<m;
	return 0;
} 
