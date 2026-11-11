#include<bits/stdc++.h>
//#define int long long 
using namespace std;
const int BIG=2e6;
int c,n,m,d,q,w[BIG],k,t,b[50005][505],a1,ans,x,y,spend[505][50005];
struct ff{
	int x,w,k;
};
vector<int>b1[BIG],a[BIG];
queue<ff>p;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a1>>t;
			a[i].push_back(a1);
			b1[a1].push_back(i);
			b[a1][i]=t;
		}
	}
	while(q--)
	{
		cin>>x>>y;
		ans=1e9;
		bool pd[BIG]={0};
		for(int i=1;i<=m;i++)
			for(int j=1;j<=504;j++)spend[j][i]=1e9;
		p.push({x,0,0});
		while(!p.empty())
		{
			int now=p.front().x,cost=p.front().w,subway=p.front().k;
			p.pop();
			if(now==y)
			{
				ans=min(ans,cost+b[now][subway]);
				continue;
			}
			for(auto i:b1[now])
			{
				if(spend[i][now]<=cost+b[now][subway]+b[now][i])continue;
				if(i==subway)continue;
				p.push({now,cost+b[now][subway]+b[now][i],i});
				spend[i][now]=cost+b[now][subway]+b[now][i];
			}
			for(auto i:a[subway])
			{
				if(spend[subway][i]<=cost)continue;
				if(i==now)continue;
				p.push({i,cost,subway});
				spend[subway][i]=cost;
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
