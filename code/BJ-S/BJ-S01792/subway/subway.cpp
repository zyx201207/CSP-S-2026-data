#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int XIAN=505,TAI=5e5+5;

int test,xian,tai,d,q;
int waste[TAI],k[XIAN],sk[XIAN];
int a[TAI],t[TAI];
struct node
{
	int id,time;
};
vector<node>cross[TAI];
LL f[XIAN][XIAN];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&test,&xian,&tai,&d,&q);
	for (int i=1;i<=tai;i++)
	{
		scanf("%d",&waste[i]);
	}
	for (int i=1;i<=xian;i++)
	{
		scanf("%d",&k[i]);
		sk[i]=sk[i-1]+k[i];
		for (int j=sk[i-1]+1;j<=sk[i];j++)
		{
			scanf("%d%d",&a[j],&t[j]);
			cross[a[j]].push_back(node{i,t[j]});
		}
	}
	memset(f,0x3f,sizeof f);
	for (int i=1;i<=tai;i++)
	{
		for (node j:cross[i])
		{
			for (node k:cross[i])
			{
				f[j.id][k.id]=min(f[j.id][k.id],(LL)j.time+k.time);
			}
		}
	}
	for (int i=1;i<=xian;i++)
		f[i][i]=0;
	for (int i=1;i<=xian;i++)
	{
		for (int j=1;j<=xian;j++)
		{
			for (int k=1;k<=xian;k++)
			{
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		LL ans=1e18;
		for (node i:cross[x])
		{
			for (node j:cross[y])
			{
				ans=min(ans,f[i.id][j.id]+i.time+j.time);
			}
		}
		ans+=waste[x]+waste[y];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/