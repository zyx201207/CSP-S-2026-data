#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],b[200010][40],siz[200010],lc,t[200010][40],maxx,cm[40],sum=0;
inline void dfs(int x,int now,int z)
{
	if(x==n+1)
	{
		if(now==m+1)
		{
			maxx=max(maxx,z);
		}
		return ;
	}
	if(now==m+1)
	{
		maxx=max(maxx,z);
		return ;
	}
	lc=z;
	if(z==-1)
	{
		lc=a[x];
	}
	else
	{
		lc&=a[x];
	}
	dfs(x+1,now+1,lc);
	dfs(x+1,now,z);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cm[0]=1;
	for(int i=1;i<=30;i++)
	{
		cm[i]=cm[i-1]*2;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		lc=a[i];
		while(lc)
		{
			b[i][++siz[i]]=lc%2;
			lc/=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=30;j++)
		{
			t[i][j]=t[i-1][j]+b[i][j];
		} 
	}
	if(m==n)
	{
		sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	} 
	else if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	else if(m==2&&n<=1e4)
	{
		maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			sum=0;
			for(int j=1;j<=siz[i];j++)
			{
				lc=t[i-1][j]+t[n][j]-t[i][j];
				if(lc>=m)
				{
					sum+=cm[j-1];
				}
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx;
		return 0;
	}
	else if(n<=25)
	{
		maxx=0;
		dfs(1,1,-1);
		cout<<maxx;
	}
	else 
	{
		for(int i=1;i<=n;i++)
		{
			sum=0;
			for(int j=1;j<=siz[i];j++)
			{
				lc=t[i][j]-t[max(i-m,0ll)][j];
				if(lc>=m)
				{
					sum+=cm[j-1];
				}
			}
			maxx=max(maxx,sum);
	//		cout<<"\n";
		}
		cout<<maxx;
	}
	return 0;
}

