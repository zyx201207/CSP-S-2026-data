#include<bits/stdc++.h>
using namespace std;
int a[200005];
int f[200005];
int tong[200005];
int s[200005];
int n,m,flag=1,cnt=1,fl=1;
void dfs(int len,int pos)
{
	if(len>=m)
	{
		s[cnt]=pos;
		cnt++;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i]==0)
			{
				f[i]=1;
				dfs(len+1,pos&a[i]);
				f[i]=0;
			}
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
		if(a[i]!=i-1)
		{
			flag=0;
		}
		else if(a[i]>4)
		{
			fl=0;
		}
	}
	if(m==1)
	{
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
		return 0;
	}
	else if(m==n)
	{
		int sum=1;
		for(int i=1;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	else if(m==2)
	{
		int ma=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	else if(m==n-1)
	{			
		int ma=0;
		sort(a+1,a+n+1,greater<int>());
		for(int i=1;i<=n;i++)
		{
			f[i]=1;
			int sum;
			if(i==1)
			{
				sum=a[2];
			}
			else
			{
				sum=a[1];
			}
			for(int j=1;j<=n;j++)
			{
				if(f[j]!=0)
				{
					sum=sum&a[j];
				}
			}
			f[i]=0;
			ma=max(ma,sum);
		}
		cout<<ma;
		return 0;
	}
	else 
	{
		sort(a+1,a+n+1,greater<int>());
		dfs(0,a[1]);
		int ma=0;
		for(int i=1;i<=cnt;i++)
		{
			ma=max(ma,s[i]);
		}
		cout<<ma;
	}
	return 0;
}
