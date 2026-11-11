#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[3005],b[5005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf(" %d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int sum[3005]={0},k=0;
		for(int j=i;j<=n;j++)
		{
			if(sum[a[j]]==0||sum[a[j]]>=k)
			{
				k++;
				b[k]=a[j];
				sum[a[j]]=k;
			}
			else  k=sum[a[j]];
		}
		for(int j=1;j<=k;j++)
		ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
