#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+10,M=2e6+10;
vector<int> mp[N];
int a[M],cnt[N],dis[N];
queue<int> q;
bitset<N> vis;
void work110()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		mp[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=d)
			{
				mp[i].push_back(j);
				mp[j].push_back(i);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[j]=1e18;
			cnt[j]=0;
		}
		vis.reset();
		dis[i]=0;
		cnt[i]=1;
		while(!q.empty())
		{
			q.pop();
		}
		q.push(i);
		while(!q.empty())
		{
			int nw=q.front();
			q.pop();
			if(vis[nw])continue;
			vis[nw]=1;
			for(auto v:mp[nw])
			{
				if(v<i)
				{
					continue;
				}
				if(dis[v]<=dis[nw])continue;
				q.push(v);
				dis[v]=dis[nw]+1;
				cnt[v]+=cnt[nw];
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(cnt[j]==2&&j>i)
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
void workA()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<0<<'\n';
		return ;
	}
	int d=a[2]-a[1];
	m/=d;
	if(m<=1)
	{
		cout<<0<<'\n';
		return;
	}
	cout<<max(0ll,n-(2*m-1))<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		if(c<=10)work110();
		if(11<=c&&c<=12)workA();
	}
	return 0;
}