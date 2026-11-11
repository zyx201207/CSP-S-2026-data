#include<bits/stdc++.h>
#define ll long long
#define MAXN 2147483647
//#define MAXN 9223372036854775807
using namespace std;
int c,n,m,d,q,dz,dn,dw,ans,w[510000];//进站时间
struct node{
	bitset<577>b;
}a[510000];
int sch[510000][23][2];//处理用数据
int nim[514][514];//邻接矩阵预处理+
int menu[510000][514];//保留问题，保分（最后一舞，不拼测评机了）
int lookfor(int USELINE,int USESTAT)//xianming+zhantai
{
	if(menu[USELINE][USESTAT]!=0)return menu[USELINE][USESTAT];
	else
		for(int i=1;i<=sch[USESTAT][0][0];i++)
			if(sch[USESTAT][i][0]==USELINE){
				menu[USELINE][USESTAT]=sch[USESTAT][i][1];
				return menu[USELINE][USESTAT];
			}
	exit(401);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			nim[i][j]=MAXN;
		}
	}
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&dz);
		for(int j=1;j<=dz;j++)
		{
			scanf("%d%d",&dn,&dw);//i->a站+中转t
			a[dn].b[i]=1;//dn站是否包含i线路 
			sch[dn][(++sch[dn][0][0])][1]=dw;// 0ti
			sch[dn][(sch[dn][0][0])][0]=i;// 1a
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(sch[i][0][0]>1)
		for(int j=1;j<sch[i][0][0];j++)
		{
			for(int k=j+1;k<=sch[i][0][0];k++)
			{
				nim[sch[i][j][0]][sch[i][k][0]]=sch[i][j][1]+sch[i][k][1];
				nim[sch[i][k][0]][sch[i][j][0]]=sch[i][j][1]+sch[i][k][1];
			}
		}
	}
	bool f=0;
	for(int k=1;k<=n;k++)//仅维护小到大 
	{
		if(f)break;
		f=1;
		for(int i=1;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(nim[i][j]!=MAXN)
				for(int l=j+1;l<=n;l++)
				{
					if(nim[j][l]!=MAXN)
					{
						if(nim[i][l]>nim[i][j]+nim[j][l]){f=0,nim[i][l]=nim[i][j]+nim[j][l];}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{nim[i][i]=0;
		for(int j=1;j<=n;j++)
		{
			nim[i][j]=min(nim[i][j],nim[j][i]);
		}
	}
	for(int ttk=1;ttk<=q;ttk++)
	{
		scanf("%d%d",&dn,&dw);ans=MAXN;
		for(int i=1;i<=n;i++)
		{
			if(a[dn].b[i])//查询站点，开始遍历 
			{
				if(a[dw].b[i])ans=min(ans,w[dn]+lookfor(i,dn)+w[dw]+lookfor(i,dw));
				else
				{
					for(int j=1;j<=n;j++)
					{
						if(i==j)continue;
						if(a[dw].b[j])
							ans=min(ans,w[dn]+lookfor(i,dn)+w[dw]+lookfor(j,dw)+nim[i][j]);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
