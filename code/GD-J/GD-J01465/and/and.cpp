#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int a[N],b[N],n,m,mx=0;
void dfs(int x,int cnt)
{
	b[cnt+1]=a[x];
	if(cnt+1==m)
	{
		int ans=b[1];
		for(int i=2;i<=m;i++)ans=ans&b[i];
		// for(int i=1;i<=m;i++)cout<<b[i]<<" ";cout<<"\n";
		// cout<<ans<<"\n";
		mx=max(mx,ans);
		return;
	}
	for(int i=x+1;i<=n-m+1;i++)dfs(i,cnt+1);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20)
	{
		for(int i=1;i<=n-m+1;i++)dfs(i,0);
		cout<<mx;
		return 0;
	}
	else
	{
		int mm=a[1];
		if(m==1)
		{
			for(int i=1;i<=n;i++)mm=max(mm,a[i]);
			cout<<mm;
			return 0;
		}
		else if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					mm=max(mm,a[i]&a[j]);
				}
			}
			cout<<mm;
			return 0;
		}
		else if(m==n)
		{
			for(int i=1;i<=n;i++)mm=mm&a[i];
			cout<<mm;
			return 0;
		}
		else cout<<0;
	}
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
