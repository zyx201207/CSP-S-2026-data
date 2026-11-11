#include<bits/stdc++.h>
using namespace std;
int n,a[511000],m,s[511000],ans=0,cnt=0;
void dg(int c,int b)
{
	if(c>n)
	{
		if(b==m)
		{
			int maxx=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]==1&&maxx==0)
				{
					maxx=a[i];
				}
				else if(s[i]==1)
				{
					maxx&=a[i];
				}
			}
			ans=max(ans,maxx);
		}
	}
	else
	{
		for(s[c]=0;s[c]<=1;s[c]++)
		{
			dg(c+1,b+s[c]);
		}
	}
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				ans=a[i];
			}
			else
			{
				ans&=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		int maxx=0;
		for(int i=1;i<n;i++)
		{
			maxx=a[i];
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,maxx&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			int maxx=-1;
			for(int j=1;j<=n;j++)
			{
				if(j!=i&&maxx==-1)
				{
					maxx=a[j];
				}
				else if(j!=i)
				{
					maxx&=a[j];
				}
			}
			ans=max(maxx,ans);
		}
		cout<<ans;
		return 0;
	}
	else 
	{
		dg(1,0);
		cout<<ans;
		return 0;
	}
	return 0;
}
