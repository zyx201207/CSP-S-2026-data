#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005],ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int p=1;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]!=0)
			{
				p=f[a[j]];
				f[a[j]]=0;
				for(int k=1;k<=m;k++)
				{
					if(f[k]>=p) f[k]=0;
				}
			}
			f[a[j]]=p;
			p++;
		}
		for(int j=1;j<=m;j++)
		{
			if(f[j]!=0)
			{
				ans[j]++;
				f[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
