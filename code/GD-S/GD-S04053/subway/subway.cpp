#include<bits/stdc++.h>
struct vec
{
	int *sz,*sz1,top,size;
};
struct bf
{
	int num,xnum;
};
struct svec
{
	bf sz[25];
	int top;
};
struct a2
{
	int num;
	long long qz;
};
vec dt[505];
svec z[30005];
int c,n,m,d,q;
int l,r;
long long dp[1005][1005],a[10005],top,vis[1005];
a2 dui[10005];
void push(long long x,int jd)
{
	top++;
	dui[top].num=jd;
	dui[top].qz=x;
	int tmp=top;
	while(tmp!=1&&dui[tmp].qz<dui[tmp/2].qz)
	{
		std::swap(dui[tmp],dui[tmp/2]);
	}
	return;
}
int top1()
{
	return dui[1].num;
}
void del()
{
	dui[1]=dui[top];
	top--;
	int maxz,tmp=1;
	while(tmp*2<=top)
	{
		if(tmp*2+1<=top&&dui[tmp*2+1].num<dui[tmp*2].num)
		{
			maxz=tmp*2+1;
		}
		else
		{
			maxz=tmp*2;
		}
		if(dui[maxz].num<dui[tmp].num)
		{
			std::swap(dui[maxz],dui[tmp]);
			tmp=maxz;
		}
		else
		{
			break;
		}
	}
	return;
}
void djstl(int x);
int main()
{
	memset(dp,127/3,sizeof(dp));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(c<=11)
	{
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&dt[i].size);
			dt[i].sz=new int[dt[i].size+5];
			dt[i].sz1=new int[dt[i].size+5];
			for(int j=1;j<=dt[i].size;j++)
			{
				scanf("%d%d",&dt[i].sz[j],&dt[i].sz1[j]);
				z[dt[i].sz[j]].top++;
				z[dt[i].sz[j]].sz[z[dt[i].sz[j]].top].xnum=i;
				z[dt[i].sz[j]].sz[z[dt[i].sz[j]].top].num=j;
			}
		}
		for(int i=1;i<=m;i++)
		{
			int a;
			djstl(i);
			for(int j=1;j<=m;j++)
			{
				printf("%lld ",dp[i][j]);
			}
			printf("\n");
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",dp[l][r]+a[l]+a[r]);
		}
		//for()
	}
}
void djstl(int x)
{
	memset(vis,0,sizeof(vis));
	dp[x][x]=0;
	top=0;  
	push(0,x);
	while(top>0)
	{
		while(top>0&&vis[top1()]==1)
		{
			del(); 
		}       
		if(top==0)
		{
			break;
		}
		int jd=top1();
		del();
		vis[jd]=1;
		for(int i=1;i<=z[jd].top;i++)
		{
			for(int j=1;j<=dt[z[jd].sz[i].xnum].size;j++)
			{
#define lbx (z[jd].sz[i].xnum)
#define noww (z[jd].sz[i].num)
//				if(dt[lbx].sz1[dt[lbx].sz[j]]<1)
//				{
//					printf(" ");
//				}
				printf("!%d %d %d %d",jd,dt[lbx].sz[j],dp[x][jd],dt[lbx].sz1[dt[lbx].sz[j]]);
				if(dp[x][jd]+dt[lbx].sz1[noww]+dt[lbx].sz1[dt[lbx].sz[j]]<dp[x][dt[lbx].sz[j]])
				{
					dp[x][dt[lbx].sz[j]]=dp[x][jd]+dt[lbx].sz1[noww]+dt[lbx].sz1[dt[lbx].sz[j]];
					push(dp[x][dt[lbx].sz[j]],dt[lbx].sz[j]);
				}
			}
		}
		printf("^");
	}
	printf("\n");
	return;
}
