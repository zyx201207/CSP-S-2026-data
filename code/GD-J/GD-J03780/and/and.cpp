#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,maxx;
bool flag1=1,flag2=1;
void dg(int x,int sum,int num)
{
	if(sum==m)
	{
		ans=max(ans,num);
		return;
	}
	if(x>n)
	{
		return;
	}
	dg(x+1,sum+1,(sum==0?a[x]:num&a[x]));
	dg(x+1,sum,num);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if((double)log2(a[i]+1)!=(int)log2(a[i]+1))
		{
			flag1=0;
		}
		if(a[i]!=i-1)
		{
			flag2=0;
		}
	}
	if(m==1)
	{
		cout<<maxx;
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
	if(flag1)
	{
		sort(a+1,a+n+1);
		ans=a[n-m+1];
		cout<<ans;
		return 0;
	}
	if(flag2)
	{
		ans=a[n];
		for(int i=n-1;i>n-m;i--)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		int x[N]={0},y[N]={0};
		for(int i=1;i<=n;i++)
		{
			x[i]=x[i-1]&a[i];
		}
		for(int i=n;i>=1;i++)
		{
			y[i]=y[i+1]&a[i];
		}
		ans=max(x[n-1],y[2]);
		for(int i=2;i<n;i++)
		{
			ans=max(ans,x[i-1]&y[i+1]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	dg(1,0,0);
	cout<<ans;
	return 0;
}
