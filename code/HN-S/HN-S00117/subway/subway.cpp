#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,q,w[5000005],a[5000005],dp[5000005],vis[5000005],cnt;
map<pair<int,int>,int>id;
struct N{
	int y,w;
};
bool operator < (N x,N y){
	return x.w<y.w;
}
vector<N>l[5000005];
void dij(int s)
{
	priority_queue<N>q;
	for(int i=1;i<=n;i++)
	{
		if(id.find({s,i})==id.end())
			continue;
		q.push({id[{s,i}],a[id[{s,i}]]});
		dp[id[{s,i}]]=a[id[{s,i}]];
	} 
	while(q.size())
	{
		int x=q.top().y;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(int i=0;i<l[x].size();i++)
		{
			int y=l[x][i].y,w=l[x][i].w;
			if(dp[y]>dp[x]+w)
			{
				dp[y]=dp[x]+w;
				q.push({y,dp[y]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int ll;
		cin>>ll;
		int last;
		cin>>last;
		if(id.find({last,i})==id.end())
			id[{last,i}]=++cnt;
		cin>>a[id[{last,i}]];
		for(int kkk=2;kkk<=ll;kkk++)
		{
			int p=0;
			cin>>p;
			if(id.find({p,i})==id.end())
				id[{p,i}]=++cnt;
			cin>>a[id[{p,i}]];
			l[id[{last,i}]].push_back({id[{p,i}],0});
			l[id[{p,i}]].push_back({id[{last,i}],0});
			last=p;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(id.find({j,i})==id.end())
				continue;
			if(id.find({j,i-1})==id.end())
				continue;
			l[id[{j,i-1}]].push_back({id[{j,i}],a[id[{j,i-1}]]+a[id[{j,i}]]});
			l[id[{j,i}]].push_back({id[{j,i-1}],a[id[{j,i}]]+a[id[{j,i-1}]]});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=0;i<=cnt;i++)
		{
			vis[i]=0,dp[i]=1e18;
		}
		dij(x);
		int mini=1e18;
		for(int i=1;i<=n;i++)
		{
			mini=min(mini,dp[id[{y,i}]]+a[id[{y,i}]]);
		}
		cout<<mini+w[x]+w[y]<<"\n";
	}
	return 0;
}


//5  7  6
//1->2->4
// /
//2->3->5
//3  4  7
//2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
