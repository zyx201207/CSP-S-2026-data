#include<bits/stdc++.h>
using namespace std;
struct str
{
	int val;
	int road=0;
};
int c,n,m,d,q;
long long sta[500005];
long long cost[505][505];
bool isv[505][505];
str cha[500005][25];
long long read()
{
	char ch;
	long long ret=0;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		ret=(ret<<1)+(ret<<3)+int(ch-'0');
		ch=getchar();
	}
	return ret;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	c=read(); n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;i++) //scanf("%lld",&sta[i]);
		sta[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k;
		//scanf("%d",&k);
		k=read();
		for(int j=1;j<=k;j++)
		{
			int a,p=1;
			long long t;
			//scanf("%d%lld",&a,&t);
			a=read(); t=read();
			for(;p<=d&&cha[a][p].road>0;p++)
			{
				int road=cha[a][p].road;
				if(cost[i][road]<=0)
				{
					cost[i][road]=cost[road][i]=t+cha[a][p].val;
					continue;
				}
				cost[i][road]=cost[road][i]=min(cost[i][road],t+cha[a][p].val);
			}
			cha[a][p].road=i;
			cha[a][p].val=t;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int p=1;p<=n;p++)
			{
				if(i!=j&&i!=p&&j!=p&&cost[i][p]>0&&cost[j][p]>0)
				{
					if(cost[i][j]<=0) cost[i][j]=cost[i][p]+cost[j][p];
					else cost[i][j]=min(cost[i][j],cost[i][p]+cost[j][p]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) cost[i][i]=0;
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",cost[i][j]);
		printf("\n");
	}*/
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",cha[i][j].val);
		printf("\n");
	}*/
	for(int i=1;i<=q;i++)
	{
		//cout<<"q";
		int x,y;
		long long ans=LONG_LONG_MAX;
		//scanf("%d%d",&x,&y);
		x=read(); y=read();
		for(int xx=1;xx<=d&&cha[x][xx].road>0;xx++)
			for(int yy=1;yy<=d&&cha[y][yy].road>0;yy++)
				ans=min(ans,sta[x]+sta[y]+cha[x][xx].val+cha[y][yy].val+cost[cha[x][xx].road][cha[y][yy].road]);
		printf("%lld\n",ans);
	}
	return 0;
}
