#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],sum[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		sum[a[i]]++;
		for(int j=i+1;j<=n;j++)
			if(a[j]>a[j-1])
				sum[a[j]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",sum[i]);
	return 0;
}
