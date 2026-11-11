#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
vector<int> vt[N];
queue<int> q; 
int c,T,n,d,ans;
int a[N],dis[N],cnt[N];
bool flag[N];
void bfs(int s)
{
	for(int i=s;i<=n;i++)
	{
		cnt[i]=0;
		flag[i]=false;
	}
	while(!q.empty())
		q.pop();
	dis[s]=0;
	cnt[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<vt[u].size();i++)
		{
			int v=vt[u][i];
			if(!flag[v])
			{
				dis[v]=dis[u]+1;
				cnt[v]+=cnt[u];
				flag[v]=true;
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)
				cnt[v]+=cnt[u];
		}
	}
	for(int i=s;i<=n;i++)
		if(cnt[i]==2)
			ans++;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
			vt[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
					vt[i].push_back(j);
				else
					break;
			}
		ans=0;
		for(int i=1;i<=n;i++)
			bfs(i);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
