#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int c,t;
vector <int> v[N];
stack <int> s[3];
int n,k;
bool vis[N];
int f=1;
bool book[N];
int ans;
int dis(int x,int t)
{
	if(t==x){
		return 0;
	}
	int maxx=0;
	for(int i=0;i<(int)v[t].size();i++)
	{
		int u=v[t][i];
		if(book[u]) continue;
		maxx=max(maxx,dis(x,u)+1);
	}return maxx;
}
bool check(int x)
{
	if(vis[x]) return 0;
	for(int i=0;i<(int)v[x].size();i++)
	{
		int u=v[x][i];
		if(vis[u]) return 0;
	}return 1;
}
void dfs(int x,int op,int num)
{
	if(num==k){
		int sum=1e9;
		while(s[1].size())
		{
			for(int i=1;i<=n;i++)
			{
				sum=min(sum,dis(s[1].top(),s[1].top()));
			}
			s[1].pop();
		}
		while(s[2].size())
		{
			for(int i=1;i<=n;i++)
			{
				sum=min(sum,dis(s[2].top(),s[2].top()));
			}
			s[2].pop();
		}
		ans=max(ans,sum);
	}
	if(op==1)
	{
		for(int i=0;i<(int)v[x].size();i++)
		{
			int u=v[x][i];
			if(vis[u]) continue;
			s[f].push(u);
			dfs(u,1,num+1);
			if(f==1) dfs(u,0,num+1);
		}
	}else{
		f=2;
		for(int i=1;i<=n;i++){
			if(check(i))
			{
				for(int i=0;i<(int)v[x].size();i++)
				{
					int u=v[x][i];
					if(vis[u]) continue;
					s[f].push(u);
					dfs(u,1,num+1);
				}
			}
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			s[1].push(i);
			dfs(i,1,1);
		}
		cout<<ans;
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
*/
