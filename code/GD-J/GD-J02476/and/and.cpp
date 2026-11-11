#include <bits/stdc++.h>
using namespace std;
int a[200005],n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	int maxa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				   ans=max(ans,a[i]&a[j]&a[k]);
			}
		}
	}
	else if(m==4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int h=k+1;h<=n;h++)
					    ans=max(ans,a[i]&a[j]&a[k]&a[h]);
				}
			}
		}
	}
	else if(m==5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int h=k+1;h<=n;h++)
					{
					    for(int l=h+1;l<=n;l++)
						    ans=max(ans,a[i]&a[j]&a[k]&a[h]&a[l]);
					}
				}
			}
		}
	}
	else if(m==6)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int h=k+1;h<=n;h++)
					{
					    for(int l=h+1;l<=n;l++)
						{
						    for(int g=l+1;g<=n;g++)
							    ans=max(ans,a[i]&a[j]&a[k]&a[h]&a[l]&a[g]);
						}
					}
				}
			}
		}
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
	}
	else if (m==n-1)
	{
		int sum[200005],last[200005];
		sum[1]=a[1];
		for(int i=2;i<=n;i++)
		   sum[i]=sum[i-1]&a[i];
		last[n]=a[n];
		for(int i=n-1;i>=1;)
		   last[i]=last[i+1]&a[i];
		for(int i=2;i<=n-1;i++)//假设是a【i】不参与and；
		{
			ans=max(ans,sum[i-1]&last[i+1]);
		 }
		ans=max(ans,sum[n-1]);
		ans=max(ans,last[2]);
	}
	else if(maxa<=4)
	{
		int b[10]={0};
		for(int i=1;i<=n;i++)
		{
			b[a[i]]++;
		}
		if(b[4]>=m) ans=4;
		else
		{
			if(b[3]>=m) ans=3;
			else
			{
			    if(b[3]+b[2]>=m) ans=2;
			    else
			    {
			    	if(b[3]+b[1]>=m) ans=1;
			    	else ans=0;
				}
			}
		}
	}
	else
	{
		ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
}
