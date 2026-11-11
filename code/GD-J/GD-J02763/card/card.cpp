#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],num[500005],v[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		memset(ans,0,sizeof(ans));
		memset(num,0,sizeof(num));
		for (int j=i;j<=n;j++)
		{
			int x=a[j];
			if (num[x])
			{
				for (int k=num[x];k<=n;k++)
					ans[k]=0;
			}
			num[x]=j;
			ans[j]=x;
		}
		for (int j=i;j<=n;i++)
		{
			v[ans[i]]++;
		}
	}
	for (int i=1;i<=m;i++)
		cout<<v[i]<<" ";
	return 0;
} 
