#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[200005];
void dfs(int l,long long num,int k)
{
	if(num!=0&&num<=ans)return;
	if(k==m)
	{
		ans=max(ans,num);
		return;
	}
	if(l>=n)
	return;
	if(num==0)
	dfs(l+1,a[l+1],k+1);
	else
	dfs(l+1,num&a[l+1],k+1);
	dfs(l+1,num,k);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf(" %lld",&a[i]);
	if(m==1)
	{
		long long ma=0;
		for(int i=1;i<=n;i++)
		ma=max(ma,a[i]);
		cout<<ma;
		return 0;
	}
	if(m==2)
	{
		long long ma=0;
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
	if(m==n)
	{
		int an=a[1];
		for(int i=2;i<=n;i++)
		an=(an&a[i]);
		cout<<an;
		return 0;
	}
	if(n<=25)
	{
		dfs(1,0,0);
		dfs(1,a[1],1);
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		long long ma=a[1],an=0;
		for(int i=2;i<=n;i++)
		{
			ma=a[1];
			for(int j=2;j<=n;j++)
			{
				if(j!=i)
				ma=(ma&a[j]);
			}
			an=max(ma,an);
		}
		ma=a[2];
		for(int i=3;i<=n;i++)
		ma=(ma&a[i]);
		an=max(an,ma);
		cout<<an;
		return 0;
	}
	return 0;
}
