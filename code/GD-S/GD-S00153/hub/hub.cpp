#include<bits/stdc++.h>
using namespace std;
#define int long long // <------------------------
int TTTQQQTTT,T;
int n,k;
vector<int> p[1000001];
int b[1000001];
int ans;
int df(int x,int fa)
{
	if(b[x]==1) return 0;
	int ret=1e9;
	for(int xx:p[x])
	{
		if(xx==fa) continue;
		ret=min(ret,df(xx,x));
	}
	return ret+1;
}
/*void dfs(int x,int fa,int lt,int y)
{
	if(lt<0) return;
	if(y>k)
	{
		int ret=0;
		for(int i=1;i<=n;i++)
		{
			if(!b[i])
			{
				ret=max(ret,df(i,0));
			}
		}
		ans=min(ans,ret);
		return;
	}
	int q=-1;
	if(b[fa]) q=0;
	for(int xx:p[x])
	{
		if(xx==fa) continue;
		b[x]=1;
		dfs(xx,x,lt+q,y+1);
		b[x]=0;
		dfs(xx,x,lt,y);
	}
}*/
int cnt;
int cntt=0;
void ds(int x,int fa)
{
	if(b[x]==1&&b[fa]==0)
	{
		cnt++;
	}
	if(b[x]) cntt++;
	for(int xx:p[x])
	{
		if(xx==fa) continue;
		ds(xx,x);
	}
}
void dfs(int x)
{
	if(x>n)
	{
		cnt=0;
		cntt=0;
		ds(1,0);
		if(cnt<=2&&cntt==k)
		{
			int ret=0;
			for(int i=1;i<=n;i++)
			{
				if(!b[i])
				{
					ret=max(ret,df(i,0));
				}
			}
			ans=min(ans,ret);
		}
		return;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=0;
	dfs(x+1);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>TTTQQQTTT>>T;
	if(TTTQQQTTT==13||TTTQQQTTT==14)
	{
		while(T--)
		{
			cin>>n>>k; 
			for(int i=1;i<=n;i++) vector<int>().swap(p[i]);
			for(int i=1;i<n;i++)
			{
				int u,v; cin>>u>>v;
				p[u].push_back(v);
				p[v].push_back(u);
			}
			int l=(n-1)/2;
			int r=(n-1)/2+1;
			while(k--)
			{
				if((n-1)/2-l<(n-1)/2-r)
				{
					b[l++]=1;
				}
				else b[r++]=1;
			}
			int ret=0;
			for(int i=1;i<=n;i++)
			{
				if(!b[i])
				{
					ret=max(ret,df(i,0));
				}
			}
			ans=min(ans,ret);
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(T--)
	{
		ans=1e15;
		cin>>n>>k; 
		for(int i=1;i<=n;i++) vector<int>().swap(p[i]);
		for(int i=1;i<n;i++)
		{
			int u,v; cin>>u>>v;
			p[u].push_back(v);
			p[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
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

0 1
6 5
1 2
2 5
4 5
5 3
3 6

*/
