#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,C,d,a[5005],bj[5005],dis[5005],first[5005],ct,inf=0x3f3f3f3f3f3f3f3f,cnt[5005];
typedef pair<int,int> pii;
struct node
{
	int to,next,w;
}tr[10010];
void add(int x,int y,int z)
{
	tr[++ct].to=y;
	tr[ct].next=first[x];
	tr[ct].w=z;
	first[x]=ct;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	int t;
	cin>>C>>t;
	while(t--)
	{
		cin>>n>>d;
		int res=0;
		ct=0;
		memset(first,0,sizeof(first));
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d)break;
				add(i,j,1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			memset(bj,0,sizeof(bj));
			memset(dis,0x3f,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			priority_queue<pii,vector<pii>,greater<pii> > q;
			q.push({0,i});
			dis[i]=0;
			cnt[i]=1;
			while(q.size())
			{
				pii now=q.top();
				q.pop();
				int u=now.second;
				if(bj[u])continue;
				bj[u]=1;
				for(int i=first[u];i;i=tr[i].next)
				{
					int v=tr[i].to;
					if(dis[u]+tr[i].w<=dis[v])
					{
						if(dis[u]+tr[i].w==dis[v])cnt[v]+=cnt[u];
						else cnt[v]=cnt[u];
						dis[v]=dis[u]+tr[i].w;
						q.push({dis[v],v});
					}
				}
			} 
			for(int j=i+1;j<=n;j++)if(cnt[j]==2)res++;
		}
		cout<<res<<'\n';
	}
	return 0;
}
