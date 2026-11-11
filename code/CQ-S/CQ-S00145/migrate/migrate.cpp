#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[5001],p[5001],val[5001][5001],cnt[5001][5001];
void dfs(int now,int siz,int l[])
{
	l[++siz]=now;
	//printf("%d %d\n",now,siz);
	for(int i=1;i<siz;i++)
	{
		if(val[l[i]][now]==siz-i) cnt[l[i]][now]++;
		else if(val[l[i]][now]>siz-i) val[l[i]][now]=siz-i,cnt[l[i]][now]=1;
	}
	for(int i=now+1;i<=n;i++)
	{
		printf("%d %d %d\n",now,i,a[i]-a[now]);
		if(a[i]-a[now]<=d) dfs(i,siz,l);
		else return;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		memset(val,0x3f3f3f,sizeof val);
		memset(cnt,0,sizeof cnt);
		int ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		dfs(1,0,p);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) /*if(cnt[i][j]==2) ans++;/*/printf("%d ",val[i][j]);
			printf("\n");
		}
		printf("%d\n",ans/2);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 
*/
