#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const long long inf=0x3f3f3f3f3f3f3f3f;
bool flag[N];
int n,m,cn,an,ans=0,cnt=0,ax[N],sum[N];
struct node{
	int x,sum;
	bool operator < (const node ax) const {
		return sum>ax.sum;
	}
};
vector<node> mp[N];
void dij(int an)
{
	for (int i=1;i<=n;++i)
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
				cnt=1;
				sum[y]=sum[x]+asum;
				q.push({y,sum[y]});
			}
			if(sum[y]==sum[x]+asum) ++cnt;
		}
	}
	return;
}
int main()
{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>cn>>an;
	for (int i=1;i<=an;++i)
	{
		cin>>n>>m;ans=0;
		for (int i=1;i<=n;++i)
		{
			cin>>ax[i];
			for (int j=1;j<i;++j)
			{
				if(ax[i]-ax[j]<=m)
				{
					mp[i].push_back({j,1});
					mp[j].push_back({i,1});
				}
			}
		}
		for (int i=1;i<=n;++i)
		{
			cnt=0;
			dij(i);
			if(cnt==2) ++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
