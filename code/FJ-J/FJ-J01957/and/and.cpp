#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int a[200010];
int tong[10];
int ans=-INF;
int n,m;
void dfs(int ge,int he,int x)
{
	if(ge==m+1)
	{
		ans=max(ans,he);
		return ;
	}
	if(x==n+1) return ;
	dfs(ge+1,he&a[x],x+1);
	dfs(ge,he,x+1);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool b,c;
	b=true;
	c=true;
	int ma=-INF;
	int sum;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1) sum=a[i];
		if(a[i]!=i-1) b=false;
		if(a[i]>=4) c=false;
		ma=max(ma,a[i]);
		sum=sum&a[i];
	}
	if(m==1)
	{
		cout<<ma;
		return 0;
	}
	if(m==n)
	{
		cout<<sum;
		return 0;
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			dfs(1,a[i],i);
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(c==true)
	{
		for(int i=1;i<=n;i++)
		{
			tong[a[i]]++;
		}
		for(int i=3;i>=0;i--)
		{
			m-=tong[i];
			if(m<=0)
			{
				cout<<i;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}
