#include<bits/stdc++.h>
using namespace std;
pair<int,int> PII;
const int N = 2e6 + 10;
int n,k,dist[N],pre[N],idx;
struct node
{
	int from,to,val,last;
}a[N * 2];
void add(int from,int to,int val)
{
	a[++idx] = {from,to,val,pre[from]};
}
void dij()
{
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({0,1});
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	dist[1] = 0;
	while(!q.empty())
	{
		PII p = q.top();
		q.pop();
		int d = -1;
		for(int i = dist[p.second];i;i = a[i].last)
		{
			int to = a[i].to;
			if(dist[p.second] + a[i].val < dist[to])
			{
				a[i].to = to;
			}
		}
	}
}
void solve()
{
	cin >> n >> k;
	for(int i = 1;i <= n - 1;i++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y,1); 
		add(y,x,1);
	}
	dij();
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--) solve();
}
