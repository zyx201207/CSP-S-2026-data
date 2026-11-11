#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cnt;
struct node{
	int to,nxt,u;
}edge[500005];
int head[500005];
ll dis[500005];
priority_queue<pair<ll,int>,vector<ll,int>,greater<ll,int>>> q;
void init()
{
for(int i=1;i<=500005;i++)
head[i]=3000000;
}

void add(int uu,int va,int too)
{
	edge[cnt].to=too;
	edge[cnt].u=va;
	edge[cnt].nxt=head[uu];
	head[uu]=cnt;
	cnt++;
}
void dij(int s,int t)
{
	init;
	q.push({0,t});

	while(!q.empty)
	{
		auto now=q.top;
		q.pop();
	ll y=now.first;
	ll x=noe.second;
	if(y>dis[x])
	continue;
	for(int i=head[x];~i;i=edge[i].nxt)
	{
		int op=edge[u].u;
		if(dis[edge[i].to]>dis[i]+op)
		{
			dis[edge[i].to]=dis[i]+op;
		}
		}	
	}
}
int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>head[i];
	
	
	
	
	return 0;
}
