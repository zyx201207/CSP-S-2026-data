#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,a[200005],sum=0;
	char f[200005]={'0'},w[200005]={'0'};
	char c[200005],v[200005];
	int st=0,ts=0,as=0,sun;
	string ch;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>v[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			ch+=v[i];
		}
	}
	int chs=ch.size(),sq=0;
	char a1=ch[0];
	for(int i=1;i<chs;i++)
	{
		if(ch[i]!=a1) sq=1;
	}
	if(!sq)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			c[++as]=v[i];
		}
	}
	sun=sum;
	if(sum%2!=0)
	{
		sum=sum/2+1;
		for(int i=1;i<sum;i++)
		{
			f[++st]=c[i];
		}
		for(int i=sun;i>sum;i--)
		{
			w[++ts]=c[i];
		}
		int ans=0;
		int sz=max(st,ts);
		for(int i=1;i<=sz;i++)
		{
			if(f[i]!=w[i])ans++;
		}
		cout<<ans;
	}
	else
	{
		sum=sum/2;
		for(int i=1;i<=sum;i++)
		{
			f[++st]=c[i];
		}
		for(int i=sun;i>sum;i--)
		{
			w[++ts]=c[i];
		}
		int ans=0;
		int sz=max(st,ts);
		for(int i=1;i<=sz;i++)
		{
			if(f[i]!=w[i])ans++;
		}
		cout<<ans;
	}
	return 0;
 } 
