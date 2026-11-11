#include<bits/stdc++.h>
using namespace std;
char chr[(long long)2e5+5];
long long num[(long long)2e5+5];
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	string s;
	s="";
	bool tf=1;
	char lst;
	long long mx=0;
	for(long long i=0;i<n;i++)
	{
		long long a;
		cin>>a;
		char b;
		cin>>b;
		chr[i]=b;
		num[i]=a;
		if(i==0)lst=b;
		else if(b!=lst&&tf)tf=0;
		//for(long long j=0;j<a;j++)s+=b;
		mx=max(a,mx);
	}
	if(tf)
	{
		cout<<0;
		return 0;
	}
	else tf=1;
	long long ans,ans2=0;
	ans=0;
	bool flag=1;
	if(mx<=10000)
	{
		tf=0;
		flag=0;
	}
	if(tf)
	{
		for(long long i=0;i<n/2;i++)
		{
			if(num[i]==num[n-i-1])
			{
				if(chr[i]!=chr[n-i-1])
				{
					ans2+=num[i];
				}
				
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			cout<<ans2;
			return 0;
		}
	}
	if(!flag)
	{
		for(long long i=0;i<n;i++)
		{
			for(long long j=0;j<num[i];j++)s+=chr[i];
		}
	}
	long long len=s.length();
	string a,b;
	a=s.substr(0,(len)/2);
	b=s.substr((len+1)/2,(len+1)/2+1);
	//cout<<a<<" "<<b;
	for(long long i=0;i<(long long)a.length();i++)
	{
		if(a[i]!=b[i])ans++;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
