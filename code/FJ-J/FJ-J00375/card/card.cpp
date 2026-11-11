#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],num[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int o=i;o<=n;o++) b[o]=a[o];
		for(int j=i+1;j<=n;j++)
		{
			for(int l=i;l<j;l++)
			{
				if(b[l]==b[j])
				{
					for(int t=l;t<j;t++) b[t]=0;
					break;
				}
			}
		}
		for(int k=i;k<=n;k++)
		{
			if(b[k]>0) num[b[k]]++;
		}
	}
	num[a[n]]++;
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
