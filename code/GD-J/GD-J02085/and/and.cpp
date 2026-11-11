#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,p,q;
void dg(int x,int cnt,int s)
{
	if(x==n+1||cnt==m)
	{
		if(cnt==m)
		ans=max(ans,s);
		return;
	}
	dg(x+1,cnt,s);
	if(cnt==0)
	p=x,dg(x+1,cnt+1,a[x]);
	else
	q=x,dg(x+1,cnt+1,s&a[x]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n<=20)
	{
		dg(1,0,0);
		cout<<ans;
		return 0;
	}
	if(n<=2000)
	{
		if(m==1)
		{
			for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
			cout<<ans;
			return 0;
		}
		if(m==2)
		{
			for(int i=1;i<=n;i++)
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
			ans=ans&a[i];
			cout<<ans;
			return 0;
		}
	}
	return 0;
}

