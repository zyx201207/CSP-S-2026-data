#include<bits/stdc++.h>
using namespace std;
int a[500005],f[300005],t[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				f[a[j]]=1;
			}
			else
			{
				for(k=j-1;k>=1;k--)
				{
					f[a[k]]=0;
					if(a[j]==a[k])
					{
						break;
					}
				}
				f[a[j]]=1;
			}
		}
		for(j=1;j<=m;j++)
		{
			if(f[a[j]]!=0)
			{
				t[a[j]]++;
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
}
