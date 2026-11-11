#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn],b[maxn];
int sum[maxn],ans[maxn];
int cnt;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(sum,0,sizeof(sum));
		cnt=0;
		for(int j=i;j<=n;j++)
		{
			if(sum[a[j]]==0)
			{
				b[++cnt]=a[j];
				sum[a[j]]=1;
			}
			else
			{
				while(b[cnt]!=a[j])
				{
					sum[b[cnt]]=0;
					cnt--;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(sum[j]==1)
		    {
		    	ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
