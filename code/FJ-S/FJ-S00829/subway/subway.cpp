#include<bits/stdc++.h>
using namespace std;
const int N=500510;
const long long inf=0x3f3f3f3f3f3f3f3f;
bool flag[N];
int n,m,cn,an,qu,ax[N];
long long T,sum[N],ans[100010];
struct node{
	int x,sum;
	bool operator < (const node ax) const {
		return sum>ax.sum;
	}
};
struct ndoe{
	int x,y;
};
ndoe wx[100010];
vector<int> qx[510];
vector<int> cnt[N];
vector<node> mp[N];
void dij(int an)
{
	for (int i=1;i<=m+n;++i)
	  flag[i]=false,sum[i]=inf;
	priority_queue<node> q;
	sum[an]=0;q.push({an,0});
	while (q.empty()==false)
	{
		int ax=q.top().x;
		q.pop();
		if(flag[ax]==true) continue;
		else flag[ax]=true;
		for (auto cx:mp[ax])
		{
			int x=ax,y=cx.x,asum=cx.sum;
			if(sum[y]>sum[x]+asum)
			{
				sum[y]=sum[x]+asum;
				q.push({y,sum[y]});
			}
		}
	}
	return;
}
void dfs(int an)
{
	for (int i=1;i<=m+n;++i)
	  flag[i]=false;
	queue<int> q;
	flag[an]=true;sum[an]=0;q.push(an);
	while (q.empty()==false)
	{
		int ax=q.front();
		q.pop();
		for (auto cx:mp[ax])
		{
			if(flag[cx.x]==true) continue;
			else flag[cx.x]=true;
			sum[cx.x]=sum[ax]+1;
			q.push(cx.x);
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cn>>n>>m>>an>>qu;
	for (int i=1;i<=m;++i)
	  cin>>ax[i];
	for (int i=1;i<=n;++i)
	{
		int wx;
		cin>>wx;
		for (int j=1;j<=wx;++j)
		{
			int x,y;
			cin>>x>>y;
			T=y;
			cnt[x].push_back(i);
			mp[m+i].push_back({x,y});
			mp[x].push_back({m+i,y});
		}
	}
	for (int i=1;i<=qu;++i)
	{
		cin>>wx[i].x>>wx[i].y;
		ans[i]=inf;
		for (auto cx:cnt[wx[i].x])
		  qx[cx].push_back(i);
	}
	if(cn>=12&&cn<=19)
	{
		for (int i=1;i<=n;++i)
		{
			dfs(m+i);
			for (auto cx:qx[i])
			{
				int x=wx[cx].x,y=wx[cx].y,id=cx;
				ans[id]=min(ans[id],sum[x]+sum[y]+ax[x]+ax[y]);
			}
		}
	}
	else
	{
		for (int i=1;i<=n;++i)
		{
			dij(m+i);
			for (auto cx:qx[i])
			{
				int x=wx[cx].x,y=wx[cx].y,id=cx;
				ans[id]=min(ans[id],(sum[x]+sum[y])*T+ax[x]+ax[y]);
			}
		}
	}
	for (int i=1;i<=qu;++i)
	  cout<<ans[i]<<'\n';
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
