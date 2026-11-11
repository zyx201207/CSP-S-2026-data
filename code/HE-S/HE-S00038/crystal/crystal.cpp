#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt,ans[500005];
void other(int x,int y[500005])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(y[j]-y[i]==1||y[i]-y[j]==1)
			{
				if(x>=1)	x--;
			}
			if(y[j]-y[i]==2||y[i]-y[j]==2)
			{
				if(x>=2)	x-=2;
			}
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(m--)	other(m,a);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&a[i]==a[j])
			{
				cnt+=2;
				ans[i]==a[i];
			}
			if(ans[j]!=0)	cnt++;
		}
	}
	return 0;
}
