#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6;
int c,t;
int n,k;
vector<int>vect[N];
int st,en;
int d[N];
bool vis[N];
struct node{
	int u,w;
	bool operator <(const node &a)const{
		return w>a.w;
	};
};
void dijkstra()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		d[i]=LLONG_MAX/2;
	}
	d[st]=0;
	priority_queue<node>q;
	q.push({st,0});
	while(!q.empty())
	{
		cout<<"YES\n";
		node t=q.top();q.pop();
		if(vis[t.u])continue;
		vis[t.u]=1;
		for(auto v:vect[t.u])
		{
			if(d[v]>d[t.u]+1)
			{
				d[v]=d[t.u]+1;
				q.push({v,d[v]});
			}
		}
	}
}
bool  bfs()
{
	int cnt=0;
	queue<node>q;
	q.push({st,0});
	for(int i=1;i<=n;i++)vis[i]=0;
	while(!q.empty())
	{
		node t=q.front();q.pop();
		if(vis[t.u]||t.w>d[en])continue;
		vis[t.u]=1;
		cnt++;
		if(cnt>=k)return 1;
		for(auto v:vect[t.u])
		{
			q.push({v,t.u+1});
		}
	}	
	return 0;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		vect[u].push_back(v);
		vect[v].push_back(u);
	 } 
	 int res=LLONG_MAX;
	 
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)//枚举两个最远的点 
		{
			st=i,en=j;
			dijkstra();
			if(res<=d[en])continue;
			if(bfs()==1)res=min(res,d[en]);
		}
	}
	cout<<res<<endl;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>t;
	while(t--)solve();
}
/*
0 2
5 2 
1 2 
2 3
3 4
4 5
10 3
1 2
1 3
2 4 
2 5
3 6
3 7
3 8
7 9
9 10
*/
