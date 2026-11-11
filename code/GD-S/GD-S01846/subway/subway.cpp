#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[500005];
vector<pair<int,int>>sub[500005];
ll dis[505][505];
void read(int &x)
{
	char ch=0;
	x=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	read(c);
	read(n);
	read(m);
	read(d);
	read(q);
	for(int i=1;i<=m;i++)
	{
		read(w[i]);
	}
	for(int i=1,k,v,cst;i<=n;i++)
	{
		read(k);
		for(int j=1;j<=k;j++)
		{
			read(v);
			read(cst);
			sub[v].push_back({i,cst});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(pair<int,int>dt1:sub[i])
		{
			for(pair<int,int>dt2:sub[i])
			{
				if(dt1.first==dt2.first)continue;
				dis[dt1.first][dt2.first]=min(dis[dt1.first][dt2.first],(ll)dt1.second+dt2.second);
				dis[dt2.first][dt1.first]=min(dis[dt2.first][dt1.first],(ll)dt1.second+dt2.second);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(dis[i][k]==1e18)continue;
			for(int j=1;j<=n;j++)
			{
				if(i==j||dis[k][j]==1e18)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int xr,yr;
	while(q--)
	{
		scanf("%d%d",&xr,&yr);
		ll ans=1e18;
		for(pair<int,int>dt1:sub[xr])
		{
			for(pair<int,int>dt2:sub[yr])
			{
				ans=min(ans,dis[dt1.first][dt2.first]+(ll)dt1.second+(ll)dt2.second+(ll)w[xr]+(ll)w[yr]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
