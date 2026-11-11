#include <bits/stdc++.h>
using namespace std;
#define gc() getchar() 
int read()
{
	int x=0,f=1;
	char c=gc();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=gc();
	}
	while(c>='0'&&c<='9') 
	{
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,x;
	char c;
	s="";
	cin>>n;
	while(n--)
	{
		cin>>x>>c;
		while(x--) s+=c;
	}
	if(s.size()%2==0)
	{
		int cnt=s.size()/2,ans=0;
		for(int i=0;i<cnt;i++)
		{
			if(s[i]=s[i+cnt])ans++; 
		}
		cout<<ans;
	}
	else
	{
		int cnt=s.size()/2,ans=0;
		for(int i=0;i<=cnt;i++)
		{
			if(s[i]=s[i+cnt])ans++; 
		}
		cout<<ans;
	}
	return 0;
}
