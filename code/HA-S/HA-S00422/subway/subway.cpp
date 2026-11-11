#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,st,ed,ans;
int w[500005],k[500005];
int a[500005][500005],t[500005][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d %d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&st,&ed);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				ans+=t[i][j];
			}
		}
		printf("%d",&ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
