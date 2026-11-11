#include<bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pll pair<LL,LL>
#define mkp make_pair
#define rep(i,a,b,g) for(LL i=a;i<=b;i+=g)
using namespace std;
LL n,m,d,q,dis[510][510],w[500010],k[510];
vector<pll>a[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	rep(i,1,n,1)dis[i][i]=0;
	rep(i,1,m,1)cin>>w[i];
	LL t1,t2;
	rep(i,1,n,1)
	{
		cin>>k[i];
		rep(j,1,k[i],1)
		{
			cin>>t1>>t2;
			a[t1].push_back(mkp(i,t2));
		}
	}
	rep(x,1,m,1)
	{
		for(pll i:a[x])
		{
			for(pll j:a[x])
			{
				if(i==j)continue;
				dis[i.first][j.first]=min(dis[i.first][j.first],i.second+j.second);
			}
		}
	}
	rep(k,1,n,1)
	{
		rep(i,1,n,1)
		{
			rep(j,1,n,1)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	rep(i,1,n,1)
//	{
//		rep(j,1,n,1)
//		{
//			cout<<i<<' '<<j<<':'<<dis[i][j]<<'\n';
//		}
//	}
	LL u,v,mc;
	while(q--)
	{
		cin>>u>>v;
		mc=INF;
		for(pll i:a[u])
		{
			for(pll j:a[v])
			{
				mc=min(mc,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<mc+w[u]+w[v]<<'\n';
	}
	return 0;
}
