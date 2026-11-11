#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int n,m,ma=-1;
int v[10000005];
void dfs(int cnt,int l)
{
	if(l==m)
	{
		ma=max(ma,cnt);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			
			if(l!=0)dfs(cnt&a[i],l+1);
			if(l==0) dfs(a[i],l+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==2)
	{
		int mx=-1;
		for(int i=1;i<=n;i++)
		{
			mx=max(a[i]&a[i+1],ma);


		}
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		int su=a[0];
		for(int i=2;i<=n;i++)
		{
			su=su&a[i];
		}
		cout<<su;
		return 0;
	}
	if(m==n-1)
	{
		int x,y;
		x=a[1];
		y=a[n];
		for(int i=2;i<=n-1;i++)
		{
			x=x&a[i];
		}
		for(int i=n-1;i>=2;i--)
		{
			y=y&a[i];
		}
		cout<<max(x,y);
		return 0;
	}
	dfs(0,0);
	cout<<ma;
	return 0;
}

			



