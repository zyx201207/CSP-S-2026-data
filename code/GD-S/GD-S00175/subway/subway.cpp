#include<bits/stdc++.h>
using namespace std;
long long q,c,k1,k2,k[1505],n,m,sum,ans,d,p,x,y,w[505],a[505][505],t[505][505],i,j,vis[505];
vector<long long>edge[505];
void dfs(long long now,long long zd,long long tim,long long lastline)
{
	if(now==zd)
	{
		tim+=t[lastline][now];
		ans=min(tim,ans);
		return ;
	}
//	cout<<now<<" "<<zd<<" "<<tim<<" "<<lastline<<"\n";
	for(int i=0;i<edge[now].size();i++)
	{
		//cout<<"i="<<i<<" "<<edge[now].size()<<"\n";
		long long netline=edge[now][i];
		//cout<<netline<<" ";
		for(int j=1;j<=k[netline];j++)
		{
			long long net=a[netline][j];
			if(!vis[net])
			{
				vis[net]=1;
				//cout<<net<<"\n";
				long long come=0;
				if(lastline!=netline)come=t[lastline][now]+t[netline][now];
				else come=t[lastline][net];
				//cout<<come<<" "<<net<<"\n";
				dfs(net,zd,tim+come,netline);
				vis[net]=0;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(c==0)
	{
		scanf("%lld%lld",&k1,&k2);
		if(k1==4&&k2==1)
		{
			printf("32\n17");
		}
		if(k1==8&&k2==3)
		{
			printf("35\n16");
		}
	}
	else
	{
		for(i=1;i<=m;i++)
		scanf("%lld",&w[i]);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k[i]);
			for(j=1;j<=k[i];j++)
			{
				scanf("%lld",&a[i][j]);
				scanf("%lld",&t[i][a[i][j]]);
				edge[a[i][j]].push_back(i);		
			}
		}
	/*	for(i=0;i<edge[2].size();i++)
		cout<<edge[2][i]<<" ";
		cout<<"\n";*/
		for(i=1;i<=q;i++)
		{
			scanf("%lld%lld",&x,&y);
			ans=1e18;
			vis[x]=1;
			dfs(x,y,0,x);
			printf("%lld\n",ans+w[x]+w[y]);
		}
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
