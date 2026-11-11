#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000005];
int vis[2000005];
int vis1[2000005];
int vis2[2000005];
vector<int> e[2000005];
struct node
{
	int id,step;
};
void bfs(int s)
{
	queue<node> q;
	q.push({s,0});
	while(!q.empty())
	{
		node s=q.front();
		q.pop();
		
		int now=s.id;
		if(vis[now])
		continue;
		vis[now]=s.step;
		for(int i=0;i<e[now].size();i++)
		{
			int son=e[now][i];
			if(vis[son])
			continue;
			q.push({son,s.step+1});
		}
	}
}
void bfs1(int s)
{
	queue<node> q;
	q.push({s,0});
	while(!q.empty())
	{
		node s=q.front();
		q.pop();
		
		int now=s.id;
		vis1[now]++;
		for(int i=0;i<e[now].size();i++)
		{
			int son=e[now][i];
			if(vis[son]<(s.step+1))
			continue;
			if(vis1[son])
			continue;
			q.push({son,s.step+1});
		}
	}
}
void bfs2(int s)
{
	queue<node> q;
	q.push({s,0});
	while(!q.empty())
	{
		node s=q.front();
		q.pop();
		
		int now=s.id;
		vis2[now]++;
		for(int i=0;i<e[now].size();i++)
		{
			int son=e[now][i];
			if(vis[son]<(s.step+1))
			continue;
			q.push({son,s.step+1});
		}
	}
}
void solve1()
{
	for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			e[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;x[j]-x[i]<=d && j<=n;j++)
			{
				e[i].push_back(j);
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				vis[j]=0;
				vis1[j]=0;
				vis2[j]=0;
			}
			bfs(i);
			bfs1(i);
			bfs2(i);
			
			
			for(int j=i+1;j<=n;j++)
			{
				//cout<<vis1[j]<<" "<<vis2[j]<<"\n";
				if(vis1[j]==2 && vis2[j]==2)
				{
					ans++;
				}
			}
		}
		
		cout<<ans<<"\n";
}
int xx[2000005];
void solve2()
{
	if(d<=x[n]) 
	cout<<"0\n";
	else
	cout<<n<<"\n";
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0); 
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		if(n<=5000)
		solve1();
		else
		solve2();
	}
	
	
	
	return 0;
}
