#include<bits/stdc++.h>
using namespace std;
int n,m,d,q;
struct ac
{
	long long id,val;
};
struct ak
{
	int qi,zh;
}ask[100010];
set<int>table;
long long ans[510][510];
vector<ac>edge[1000510];
long long a[510],cnt;
long long dis[1000510];
bool f[1000510];
void dij(int st)
{
	memset(dis,0x3f,sizeof dis);
	memset(f,0,sizeof f);
	priority_queue<pair<int,int>>dui;
	dis[st]=0;
	dui.push({0,st});
	while(!dui.empty())
	{
		auto u=dui.top();
		dui.pop();
		if(f[u.second])
		{
			continue;
		}
		f[u.second]=1;
		for(ac v:edge[u.second])
		{
			if(dis[u.second]+v.val<dis[v.id])
			{
				dis[v.id]=dis[u.second]+v.val;
				dui.push({-dis[v.id],v.id});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>m>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int last=-1,len,b,c;
	cnt=n;
	for(int i=1;i<=m;i++)
	{
		last=-1;
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			cin>>b>>c;
			cnt++;
			if(last!=-1)
			{
				edge[last].push_back({cnt,0});
				edge[cnt].push_back({last,0});
			}
			edge[cnt].push_back({b,c});
			edge[b].push_back({cnt,c});
			last=cnt;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ask[i].qi>>ask[i].zh;
		table.insert(ask[i].qi);
		table.insert(ask[i].zh);
	}
	for(int s:table)
	{
		dij(s);
		for(int ss:table)
		{
			if(s!=ss)
			{
				ans[s][ss]=dis[ss]+a[s]+a[ss];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[ask[i].qi][ask[i].zh]<<"\n";
	}
	return 0;
}
