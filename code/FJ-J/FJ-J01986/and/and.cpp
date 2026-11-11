#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[35],c[35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxx=0,ans,maxx1=0,ANS=0,ANS1=0;
	cin>>n>>m;
	b[0]=1;
	for(int i  = 1;i<=30;i++)
	{
		b[i]=b[i-1]*2;
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(i==1)
		{
			ans=a[i];
		}
		else
		{
			ans=a[i]&ans;
		} 
	}
	if(m==1)
	{
		cout<<maxx;
	}
	else if(m==n)
	{
		cout<<ans;
	}
	else if(m==2)
	{
		for(int i = 1;i<=n-1;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				maxx1=max(a[i]&a[j],maxx1);
			}
		}
		cout<<maxx1;
	}
	else if(a[1]==0)
	{
		int i=0;
		for(int j = 1;j<=30;j++)
		{
			if(a[n]==b[j])
			{
				a[n]=a[n-1];
				break;
			}
		}
		while(a[n]>0)
		{
			c[i]=a[n]%2;
			a[n]/=2;
			i++;
		}
		for(int j = i;j>=0&&m>0;j--)
		{
			if(c[j]==1)
			{
				ANS1+=b[j];
				m--;
			}
		}
		cout<<ANS1;
	}
	else
	{
		if(n%2==1)
		{
			cout<<0;
			return 0;
		}
		else
		{
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
		}
	}
}
