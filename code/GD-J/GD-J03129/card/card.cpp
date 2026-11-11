#include<cstdio>
int a[200010],d[5010],win[200010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n>500)
	{
		int last=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]!=last)win[a[i]]=i;
			last=a[i];
		}
		for(int i=1;i<=m;i++)printf("%d ",win[i]);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int now=1;
		for(int j=i;j<=n;j++)
		{
			d[now]=a[j];
			for(int k=now-1;k>=1;k--)
			{
				if(d[k]==d[now])now=k;
			}
			now++;
		}
		for(int j=1;j<now;j++)win[d[j]]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",win[i]);
	return 0;//wuwuwu mei fa AK le
}
