#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int last[M];
int pre[N];
int nxt[N];
int res[N];
int ans[M]; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		memset(res,0,sizeof(res));
		for (int j=i;j<=n;j++)
		{
			if (pre[j]>=i && res[pre[j]]!=0)
			{
				fill(res+pre[j],res+j+1,0);	
			}
			res[j]=a[j];
		}
		for (int j=i;j<=n;j++)
		{
			ans[res[j]]++;
		}
	}
	for (int i=1;i<m;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d",ans[m]);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/

