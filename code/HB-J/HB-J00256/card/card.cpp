#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],ans[300005],tail=1,flag=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])flag=0;
	}
	if(!flag)
	{
		for(int i=1;i<=n;i++)
		{
			tail=1;
			for(int j=i;j<=n;j++)
			{
				t[tail++]=a[j];
				for(int k=1;k<tail-1;k++)
				{
					if(t[k]==a[j])
					{
						tail=k+1;
						break;
					}
				}
			}
			for(int i=1;i<=tail-1;i++)
			{
				ans[t[i]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<' ';
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[j]!=a[j-1]||j==i)ans[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<' ';
		}
	}
	
	return 0;
}
