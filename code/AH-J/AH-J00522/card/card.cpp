#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N],c[N],sum[N],ss[N],ans[N],cnt;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cnt=i-1;
		for(long long j=1;j<=n-i+1;j++)
		{
			cnt++;
			b[j]=a[cnt];
			c[b[j]]++;
			if(c[b[j]]==2)
			{
				for(long long k=sum[b[j]]+1;k<j;k++)
				{
					c[b[k]]=0;
				}
				c[b[j]]=1;
			}
			sum[b[j]]=j;
		}
		for(long long j=1;j<=m;j++)
		{
			ans[j]+=c[j];
			c[j]=0;
		}
		for(long long j=1;j<=m;j++)
		{
			b[j]=0;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
