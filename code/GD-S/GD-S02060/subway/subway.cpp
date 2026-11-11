#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int M1=1005;
const int N=505,D=25;
int c,n,m,d,Q,k[N],a[M1];
long long b[M][5],x,y;
vector<pair<int,int> >v[M1];
int cnt;
void add(int x,int y,long w)
{
	v[x].push_back({y,w});
	v[y].push_back({x,w});
}
long long f[M],ans[M1][M1],w[M],t[M1];
bool ex[M];
void dij(int s)
{
	memset(f,0x3f,sizeof(f));
	memset(ex,0,sizeof(ex));
	f[s]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	q.push({0,s});
	while(!q.empty())
	{
		auto o=q.top();
		q.pop();
		int x=o.second;
		if(ex[x]) continue;
		ex[x]=1;
		for(auto i:v[x])
		{
			int y=i.first,w=i.second;
			if(f[y]>f[x]+w)
			{
				f[y]=f[x]+w;
				q.push({f[y],y});
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		ans[s][i]=f[i];
	}
}
long long Mi=1e18;
void solve2()
{
	while(Q--)
	{
		scanf("%lld%lld",&x,&y);
		long long minn=1e18;
		if(b[x][1] and b[y][1])
		{
			minn=b[x][1]+b[y][1];
		}
		if(b[x][2] and b[y][2])
		{
			minn=min(minn,b[x][2]+b[y][2]);
		}
		if(!b[x][1])
		{
			minn=min(minn,b[x][2]+Mi+b[y][1]);
		}
		if(!b[x][2])
		{
			minn=min(minn,b[x][1]+Mi+b[y][2]);
		}
		printf("%lld\n",minn+w[x]+w[y]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%lld",&a[j],&t[j]);
			if(c==20 or c==21)
			{
				b[a[j]][i]=t[j];
				if(i==1) continue;
				if(b[a[j]][1] and b[a[j]][2])
				{
					Mi=min(Mi,b[a[j]][1]+b[a[j]][2]);
				}
			}
		}
		if(c<=11)
		for(int j=1;j<=k[i];j++)
		{
			for(int p=j+1;p<=k[i];p++)
			{
				add(a[j],a[p],t[j]+t[p]);
			}
		}
	}
	if(c==20 or c==21)
	{
		solve2();
		return 0;
	}
	for(int s=1;s<=m;s++)
	{
		dij(s);
	}
	while(Q--)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",ans[x][y]+w[x]+w[y]);
	}
}
