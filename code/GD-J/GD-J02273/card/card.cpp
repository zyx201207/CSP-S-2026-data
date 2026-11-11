#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[500005],sum[300005];
	cin>>n>>m;
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int b[500005],cnt=0;
		for(int j=i;j<=n;j++)
		{
			b[++cnt]=a[j];
			for(int k=1;k<=cnt;k++)
			{
				if(b[k]==b[cnt]) cnt=k+1;
			}
		}
		for(int j=1;j<=cnt;j++) sum[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;	
}
