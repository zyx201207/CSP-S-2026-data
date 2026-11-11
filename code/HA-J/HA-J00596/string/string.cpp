#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,k,f=0,ans;
long long sum;
char ch[200005],s[100000000],q[100000],h[100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		sum+=a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(ch[i]!=ch[i+1])
		{
			f=1;
		}
	}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	if(sum%2!=0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s[++m]=ch[i];
			}
		}
		for(int i=1;i<=sum/2;i++)
		{
			q[i]=s[i];
		}
		for(int i=m;i>=sum/2+2;i--)
		{
			h[++k]=s[i];
		}
		for(int i=1;i<=k;i++)
		{
			cout<<h[i];
		}
		for(int i=1;i<=sum/2;i++)
		{
			if(q[i]!=h[i])
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(sum%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s[++m]=ch[i];
			}
		}
		for(int i=1;i<=sum/2;i++)
		{
			q[i]=s[i];
		}
		for(int i=m;i>=sum/2+1;i--)
		{
			h[++k]=s[i];
		}
		for(int i=1;i<=k;i++)
		{
			cout<<h[i];
		}
		for(int i=1;i<=sum/2;i++)
		{
			if(q[i]!=h[i])
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

