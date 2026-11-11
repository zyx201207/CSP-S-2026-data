#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,INF=0x3f3f3f3f;
long long c,n,m,my,q,w[N],a[N],t[N],k,xr,yr,dis[N];
struct Point{
	long long next,val;
};
vector<Point> v[N];
vector<long long> ans[N];
queue<long long> que;
inline void dijkstra(long long x){
	for(int i=1;i<=m;i++)
		dis[i]=INF;
	dis[x]=0;
	que.push(x);
	while(!que.empty())
	{
		long long now=que.front();
		que.pop();
		for(int i=0;i<v[now].size();i++)
		{
			Point az=v[now][i];
			long long nx=az.next,z=az.val;
			if(dis[now]+z<dis[nx])
			{
				dis[nx]=dis[now]+z;
				que.push(nx);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&my,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
			scanf("%lld%lld",&a[j],&t[j]);
		for(int j=1;j<=k;j++)
		{
			for(int o=j+1;o<=k;o++)
			{
				long long oo=t[j]+t[o];
				v[a[j]].push_back((Point){a[o],oo});
				v[a[o]].push_back((Point){a[j],oo});
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		dijkstra(i);
		for(int j=1;j<=m;j++)
			ans[i].push_back(dis[j]);
	}
	while(q--)
	{
		cin>>xr>>yr;
		long long res=ans[xr][yr-1]+w[xr]+w[yr];
		printf("%lld\n",res);
	}
	return 0;
}
