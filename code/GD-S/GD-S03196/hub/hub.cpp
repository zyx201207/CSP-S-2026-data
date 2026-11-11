#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int ans;
const int inf = 2e9;
int head[N],nxt[N * 2],to[N * 2],tot;
void add(int u,int v)
{
	nxt[++tot]=head[u];
	head[u] = tot;
	to[tot] = v;
}
int c,T;
int n,k,cnt;
bool fl[N],bk;
void dfs2(int u,int rt)
{
//	cout<<u<<' '<<rt<<endl;
	if(!fl[rt] && fl[u]) 
	{
		cnt++;
		if(cnt > 2)
		{
			bk = 0;
			return;
		}
	}
//	cout<<"2\n";
	for(int i=head[u];i;i=nxt[i])
	{
		int v = to[i];
		if(v == rt)
		{
			continue;
		}
		dfs2(v,u);
		if(!bk) return;
	}
}
int ma;
bool bz[105];
void dfs3(int u,int sum)
{
//	cout<<"3\n";
	bz[u] = 1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v = to[i];
		if(bz[v]) continue;
		if(fl[v])
		{
			dfs3(v,0);
		}
		else
		{
			ma = max(ma,sum + 1);
			dfs3(v,sum + 1);
		}
	}
}
void dfs(int x,int sum)
{
//	cout<<"1\n";
 	if(sum == k)
 	{
 		bk = 1;
 		cnt = 0;
 		dfs2(1,0);
 		if(!bk) return;
 		int sum = inf;
 		for(int i=1;i<=n;i++)
 		{
 			if(fl[i])
			{
				memset(bz,0,sizeof(bz));
				ma = 0;
				dfs3(i,0);	 
				sum = min(sum,ma);
				break;
			}	
		}
		ans = min(ans,sum);
 		return;	
	}
	if(x > n)
	{
		return;
	}
 	fl[x] = 1;
 	dfs(x+1,sum + 1);
 	fl[x] = 0;
 	dfs(x + 1,sum);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		ans = inf;
		dfs(1,0);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) head[i] = 0;
		tot = 0;
	}
	return 0;
}
