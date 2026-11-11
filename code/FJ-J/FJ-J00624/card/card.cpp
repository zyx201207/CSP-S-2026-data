#include<bits/stdc++.h>
using namespace std;
long long vis[100000];
long long a[100000];
long long pai[100000];
long long ans[100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m;
	long long zz=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=zz;
				pai[zz]=a[j];
				zz++;
			}
			else
			{
				
				for(int k=zz-1;k>=vis[a[j]];k--)
				{
					vis[pai[k]]=0;
				}
				zz=vis[a[j]];
			}
		}
		for(int l=1;l<n;l++)
		{
			if(vis[l]!=0)
			{
				ans[l]+=1;
			}
		}
	}
	for(int l=1;l<n;l++)
	{
		cout<<ans[l]<<" ";	
	}
	return 0;
}
