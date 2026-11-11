#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500005;
ll a[maxn],vis[maxn],sum[maxn];
bool flag[maxn];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(vis[a[i]]==0)
		{
			vis[a[i]]=i;
		}
		else 
		{
			for(int j=vis[a[i]];j<=i-1;j++)
			{
				flag[j]=1;
			}
			
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==1)
		{
			continue;
		}
		sum[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	for(int i=n;i>=1;i--)
	{
		if(vis[a[i]]==0)
		{
			vis[a[i]]=i;
		}
		else 
		{
			for(int j=vis[a[i]];j<=i-1;j++)
			{
				flag[j]=1;
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==1)
		{
			continue;
		}
		sum[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)
		{
			cout<<sum[a[i]]<<" "; 
		}
	}
	return 0;
 } 
/*常数太大会落固1774533，怎么优化 */
