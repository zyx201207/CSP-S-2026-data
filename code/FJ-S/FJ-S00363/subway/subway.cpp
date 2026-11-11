#include <bits/stdc++.h>
using namespace std;

const int N=1e5*5;
const int M=1e5;
int c,n,m,d,q;
int w[N];

pair<int,int> r[M];
vector<pair<int,int>> g[505];

int bfs(int st,int ed)
{
	int sum[N];
	int ans=0;
	queue<int> q;
	bool vis[N];
	vis[st]=true;
	q.push(st);
	sum[st]=g[st][g[st].size()-1].second;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			pair<int,int> s=g[u][i];
			sum[u]=INT_MAX;
			if(s.first==-1)
			{
				sum[u]=min(sum[u],sum[s.first]+s.second+g[u][g[u].size()-1].second);
				break;
			}
			
			if(vis[s.first]==false)
			{
				sum[u]=min(sum[u],sum[s.first]+s.second+g[u][g[u].size()-1].second);
				q.push(s.first);
				vis[s.first]=true;
			} 
		}
	}
	return sum[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);	
		//printf("%d ",w[i]);
	}
	//printf("\n");
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		int aa[M],tt[M];
		for(int j=1;j<=k;j++)
		{
			scanf("%d %d",&aa[j],&tt[j]);
		}
		for(int j=1;j<k;j++)
		{
			g[aa[j]].push_back(make_pair(aa[j+1],tt[j+1]));
			//printf("%d %d\n",aa[j],aa[j+1]);
		}
		g[k].push_back(make_pair(-1,tt[k]));
	}
	for(int i=1;i<=q;i++)
	{
		int st,ed;
		scanf("%d %d",&st,&ed);
		int o=w[st]+bfs(st,ed)+w[ed];
		printf("%d\n",o);
	}
	return 0;
}
