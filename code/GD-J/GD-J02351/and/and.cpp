#include <bits/stdc++.h>
using namespace std;
const long long f=pow(2,33)-1;
long long n,m,a[200005],ans,p[200005],cnt,f2=pow(2,33); 
bool cmp(int x,int y)
{
	return x>y;
}
int check()
{
	int ff=1;
	while(f2!=0)
	{
		if(f2-1==a[ff])
		{
			ff++;
		}
		f2/=2;
	}
	if(ff==n)
	{
		return 1;
	}
}
void dfs(int deep,int count,long long zhi)
{
	if(deep==n+1)
	{
		if(count==m)
		{
			ans=max(zhi,ans);
		}
		return ;
	} 
	if(count==m)
	{
		ans=max(zhi,ans);
		return ;
	}
	dfs(deep+1,count+1,zhi&a[deep+1]);
	dfs(deep+1,count,zhi);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(check())
	{
		sort(a+1,a+1+n,cmp);
		cout<<a[m]; 
		return 0;
	} 
	dfs(1,1,a[1]);
	dfs(1,0,f);
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
