#include<bits/stdc++.h>
using namespace std;
int a[2000005];
bool f[200005];
int n,m,max1=0;
void dfs(int cnt,int sum)
{
//	cout<<sum<<"\n";
	if(cnt==m)
	{
		max1=max(max1,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==false)
		{
			f[i]=true;
			dfs(cnt+1,sum&a[i]);
			f[i]=false;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	int b[100];
	for(int i=1;i<=30;i++)
	{
		b[i]=(1<<i)-1;
	 } 
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			f[i]=true;
			dfs(1,a[i]);
			f[i]=false;
		}
		cout<<max1;
		return 0;
	}
	else if(n<=2000&&m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			max1=max(a[i],max1);
		}
		cout<<max1;
		return 0;
	}
	else if(n<=2000&&m==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					max1=max((a[i]&a[j]),max1);
				}
			}
		}
		cout<<max1;
		return 0;
	}
	else if(n<=2000&&m==n)
	{
		max1=1e9; 
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			max1=min(a[i],max1);
		}
		cout<<max1;
		return 0;
	}
	else 
	{
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==i-1)
			{
				cnt++;
			}
			for(int j=0;j<=30;j++)
			{
				if(a[i]==b[j])
				{
					ans++;
					break;
				}
			}
		}
		if(cnt==n)
		{
			max1=a[n];
			for(int i=1;i<m;i++)
			{
				max1&=a[n-i];
			}
			cout<<max1;
			return 0;
		}
		if(ans==n)
		{
			sort(a+1,a+1+n);
			cout<<a[n-m+1];
			return 0;
		}
	}
	return 0;
}
