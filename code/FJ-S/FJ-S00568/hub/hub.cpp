#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
int c,T;
const int N=1e6+10;
vector<int> G[N];
int n,k;
int in[N],vis[N],r[N],rc;
void dfs(int now,int cnt)
{
	if(cnt>k||now>n)
	{
		return;
	}
	else if(cnt==k)
	{
		queue<pair<int,int> > q;
		int zc[11]={1000};
		for(int i=1;i<=k;i++)
		{
			q.push({r[i],0});
			zc[r[i]]=0;
			int vis[11]={0},aa=0;
			while(!q.empty())
			{
				auto d=q.front;
				q.pop();
				if(!vis[d])
				{
					continue;
				}
				vis[d.first]++;
				for(int v:G[d.first])
					if(vis[v])
					{
						continue;
					}
					zc[v]=max(aa,d.second+1);
					q.push({v,d.second+1});
				}
			}
		}
		int aa=*max_element(zc+1,zc+n+1);
		ans=min(ans,aa);
	}
	dfs(now+1,cnt);
	r[rc++]=now; 
	dfs(now,cnt+1)
	rc--;
}
signed main()
{
    //freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--)
	{
		cin >> n >> k;
		rc=0,ans=n;
		for(int i=1;i<=n;i++)
		{
			in[i]=0;
			G[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			in[u]++;
			in[v]++;
		}
		if(k==n)
		{
			cout << 0 << endl ;
			continue;
		}
		if(c<=3)
		{
			sdfs(1,0);
			dfs(1,0);
			cout << ans << endl;
		}
	 } 
	return 0;
}

