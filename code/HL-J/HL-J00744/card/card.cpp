#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int m,n;
int a[N],zb[N],ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	zb[1]=a[1];
	int sum=1;
	for(int b=1; b<=n; b++)
	{
		for(int i=b; i<=n; i++)
		{
			int f=0,k;
			for(int j=1; j<=sum; j++)
			{
				if(zb[j]==a[i])
				{
					f=1;
					k=j;
					break;
				}
			}
			sum++;
			if(f==1)
			{
				sum-=k;
				for(int j=1; j<=sum; j++)
				{
					zb[j]=0;
				}
			}
			zb[sum]=a[i];
		}
		for(int i=1;i<=sum;i++)
		{
			ans[zb[i]]++;
		}
		sum=1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}

	return 0;
}