#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define M 500005
int w[M],a[M]={0},t[M]={0};
long long dis[M],vis[M];
struct Item
{
	int v;
	int t;
};
vector<Item> mp[25];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d %d",&a[j],&t[j]);
			a[j]-=1;
			for(int p=j-1;p>=0;p--)
			{
				//printf("%d %d %d %d %d\n",j,a[j],p,a[p],t[j]+t[p]);
				mp[a[j]].push_back({a[p],t[p]+t[j]}),mp[a[p]].push_back({a[j],t[p]+t[j]});
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		for(int k=0;k<m+5;k++)
		{
			dis[k]=1e12,vis[k]=0;
		}
		int x,y;
		long long ans=0;
		scanf("%d %d",&x,&y);
		ans+=w[x]+w[y];
		queue<int> q;
		q.push(x-1),vis[x-1]=1,dis[x-1]=0;
		while(q.size())
		{
			int b=q.front();
			//printf("%d\n",b);
			for(int k=0;k<mp[b].size();k++)
			{
				long long nw=mp[b][k].t+dis[b],v_s=mp[b][k].v;
				//printf("%lld %d\n",nw,v_s);
				if(nw<dis[v_s])
				{
					if(vis[v_s]==0)
					{
						vis[v_s]=1;
						dis[v_s]=nw;
						//printf("dis[%d]:%lld\n",v_s,dis[v_s]);
						q.push(v_s);
					}	
				}
			}
			q.pop();
		}
		//printf("\n%lld %lld\n\n\n",dis[y-1],ans);
		ans+=dis[y-1];
		printf("%lld\n",ans);
	}
	return 0;
}
