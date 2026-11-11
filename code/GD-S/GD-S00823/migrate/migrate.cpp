#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> x;
vector<ll> ways;
vector<vector<int>> adj;
void bfs(int s,int n)
{
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{

		int u=q.front();
		q.pop();
		for(int v : adj[u])
		{
			q.push(v);
			ways[v]++;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n;
		ll d;
		cin>>n>>d;
		x.assign(n+5,0);
		adj.assign(n+5,vector<int>());
		for(int i=0;i<n;i++) cin>>x[i];
		int ans=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(abs(x[i]-x[j])<=d)
				{
					adj[i].push_back(j);
				}
			}
		}
		ways.assign(n,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) ways[j]=0;
			bfs(i,n);
			for(int j=i+1;j<n;j++)
			{
				if(ways[j]==3)
				{
					ans++;
				} 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;	
} 
/*
0 2
4 2
1 2 3 4
*/
