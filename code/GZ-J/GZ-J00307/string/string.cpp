/*
	准考证号：GZ-J00307
	学校：华麟学校
	姓名：刘凌睿 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
char s[4000005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int len=0;
	while(n--)
	{
		int a;
		char c;
		cin>>a;
		cin>>c;
		for(int i=len;i<a+len;i++)
		{
			s[i]=c;
		}
		len+=a;
	}
	bool flag=1;
	string l,r;
	if(len%2==0)
	{
		for(int i=0;i<len/2;i++)
		{
			l[i]=s[i];
		}
		int t=0;
		for(int i=len-1;i>=len/2;i--)
		{
			r[t]=s[i];
			t++;
		}
		for(int i=0;i<len/2;i++)
		{
			if(l[i]!=r[i])
			{
				flag=0;
			}
		}
	}
	else
	{
		for(int i=0;i<len/2;i++)
		{
			l[i]=s[i];
		}
		int t=0;
		for(int i=len-1;i>len/2;i--)
		{
			r[t]=s[i];
			t++;
		}
		for(int i=0;i<len/2;i++)
		{
			if(l[i]!=r[i])
			{
				flag=0;
			}
		}
	}
	if(flag==1)
	{
		cout<<0;
		return 0;
	}
	int ans=0;
	for(int i=0;i<len/2;i++)
	{
		if(l[i]==r[i]) continue;
		else ans++;
	}
	cout<<ans;
	return 0;
}
