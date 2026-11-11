#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
void solve(ll TASK)
{
	ll n,d;
	ll ANS=0;
	cin>>n>>d;
	vector<ll> pos(n+1);
	vector<vector<ll>> E(n+1,vector<ll>(0));
	for(int i=1;i<=n;i++)
		cin>>pos[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)	
		{
			if(pos[j]-pos[i]>d)break;
			E[i].push_back(j);
		}
	}
	vector<ll> dis(n+1,1e18);
	queue<ll> q;
	dis[1]=0;
	vector<bool>vis(n+1,0),ok(n+1,0);
	vector<ll> ans(n+1,0);
	q.push(1);
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		if(vis[u])continue;
		for(auto v:E[u])
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				if(ok[v])ANS-=ans[v];
				ok[v]=0;
				ans[v]=0;
				q.push(v);
			}
			else if(dis[v]==dis[u]+1&&v!=u)
			{
				ANS++;
				ans[v]++;
				if(ok[v])ANS-=ans[v],ans[v]=0;
				ok[v]=1;
			}
		}
	} 
	cout<<ANS<<endl; 
	return;//qwq
}
int main()
{
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll T=1,TASK;cin>>TASK>>T;
	while(T--)solve(TASK);
	return 0;
}

