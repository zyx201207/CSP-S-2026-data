#include <bits/stdc++.h>
using namespace std;
struct yy{
	int lx;
	int lxd;
};
int c,n,m,d,q,x,y,sum,srd;
yy dyz[50005][505]; 
int sl[50005],kt[505][50005],w[50005],k[505][50005];
bool sy[500005];
int zl(int lx,int lxd,int now);
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	yy dyz[m+5][n+5];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i][0];
		for(int j=1;j<=2*k[i][0];j++)
		{
			if(j%2==1)
			{
				cin>>srd;
				k[i][(j+1)/2]=srd;
				sl[srd]++;
				dyz[srd][sl[srd]].lx=i;
				dyz[srd][sl[srd]].lxd=(j+1)/2;
			}
			else
			{
				cin>>kt[i][j/2];
			}
		}
	}
	
	while(q--)
	{
		cin>>x>>y;
		int sum=9999999;
		for(int i=1;i<=sl[x];i++)
		{
			sum=min(zl(dyz[x][i].lx,dyz[x][i].lxd,kt[dyz[x][i].lx][dyz[x][i].lxd]),sum);
		}
		sum+=w[x]+w[y];
		cout<<sum<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
int zl(int lx,int lxd,int now)
 {
 	int noww=now;
 	if(sy[lx])//是否走过 
 	{
 		return 0;
	}
	sy[lx]=1;
	
	for(int i=1;i<=k[lx][0];i++)//路线每个站点 
	{
		int xzzd=k[lx][i];
		if(xzzd==lxd)//进路线的站点 
		{
			continue;
		}
		if(xzzd==y)//到站 
		{
			now+=kt[lx][i];
			continue;
		}
		for(int j=1;j<=sl[xzzd];j++)//当前站点是否有未走路线 
		{
			if(!(sl[xzzd]-1))//仅有一条路线 
			{
				break;
			}
			int dqlx=dyz[xzzd][j].lx,dqlxd=dyz[xzzd][j].lxd;
			int xzl=zl(dqlx,dqlxd,now+kt[dqlx][dqlxd]+kt[lx][i]);//该路线的结果 
			if(xzl)//不是死路线 
			{
				if(now!=noww)//有到站的 
				{
					now=min(now,noww+xzl);
				}
			}
		}
	}
	return now;
 }
 
