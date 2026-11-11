#include<iostream>
#include<queue>
using namespace std;
const int N = 5e5;
const int M = 3e5;
int n,m;
int cnt[M+5];
queue<int> q;
vector<int> g[N+5];
int a[N+5],lst[M+5],f[N+5],ind[N+5];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=n;i>=1;i--)
		if(lst[a[i]]==0) lst[a[i]] = i;
	
	for(int i=1;i<=n;i++)
	{
		f[i] = 1;
		
		if(i==n) break; 
		
		if(lst[a[i]]<=i) 
		{
			g[i].push_back(i+1);
			ind[i+1]++;
		}
		else 
		{
			g[i].push_back(lst[a[i]]);
			ind[lst[a[i]]]++;
		}
	}
	
	for(int i=1;i<=n;i++)
		if(ind[i]==0) q.push(i);
	
	while(q.size())
	{
		int u = q.front();q.pop();
		
		if(u==lst[a[u]]) cnt[a[u]]+=f[u];
		
		for(int v:g[u])
		{
			f[v]+=f[u];
			if(--ind[v]==0) q.push(v);
		}
	}
	
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1


我认为这是一道图论dp，于11:14开始思考，CCF能让我AK吗？ 
*/
