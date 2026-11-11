#include<bits/stdc++.h>
using namespace std;
int s,n,m,d,p,ans;
int w[50005];
int k[505];
int a[505][50005],t[505][50005];
struct add{
	int x,t,kk;
};
int dis[500005];
queue<add>q;
int f[50005][505];
int work(int x,int y)
{
	int ans=1e9;
	q.push({w[x],x,0});
	while(!q.empty())
	{
		add o;
		o=q.front();
		//cout<<o.x<<' '<<o.t<<'\n';
		q.pop();
		if(dis[o.t]<o.x)continue;
		dis[o.t]=o.x;
		if(o.t==y)
		{
			ans=min(o.x+w[y],ans);
		}
		for(int i=1;i<=n;i++)
		{
			if(f[o.t][i])
			for(int j=1;j<=k[i];j++)
			{
				if(o.kk==i)q.push({o.x+t[i][j],a[i][j],i});
				else q.push({o.x+t[i][j]+f[o.t][i],a[i][j],i});
			}
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>s>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
			f[a[i][j]][i]=t[i][j];
		}
	}
	while(p--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++)
		{
			dis[i]=1e8;
		}
		printf("%d\n",work(x,y));
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
/*
0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
*/
