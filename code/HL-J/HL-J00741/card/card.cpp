#include<bits/stdc++.h>
using namespace std;
int a[500005];
int p[300005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		for(int j=i;j<=n;j++)
		{
			int f=1;
			for(int k=1;k<=cnt;k++)
			{
				if(p[k]==a[j])
				{
					f=0;
					cnt=k;
				}
			}
			if(f==1)
			{
				cnt++;
				p[cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++)
		{
			ans[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}