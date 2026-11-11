#include<bits/stdc++.h>
using namespace std;
int n,m,g[300005],a[300005];
bool che[300005];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int t[500005];
		for(int j=i;j<=n;j++)
		{
			t[j]=a[j];
			if(che[t[j]]==1)
			{
				for(int k=j;k>=i;k--)
				{
					if(t[k]==t[j])
					{
						for(int d=k;d<j;d++)
						{
							t[d]=0;
						}
					}
				}
			}
			che[t[j]]=1;
		}
		memset(che,0,sizeof(che));
		for(int j=1;j<=m;j++)
		{
			for(int k=i;k<=n;k++)
			{
				if(t[k]==j)
				{
					g[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<g[i]<<" ";
	}
	return 0;
}
