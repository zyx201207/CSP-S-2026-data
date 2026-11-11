#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int c,T,n,m,ans,a[N],dis[N][N],l[N],vis[N],tot;
bool flag[N];
vector<int> G[N];
void dfs1(int d)
{
	vis[d]=tot;
	for(auto it:G[d])
	{
		if(vis[it]==tot||!flag[it]) continue;
		dfs1(it);
	}
}
void check()
{
	int cnt=0,res=1; tot++;
	for(int i=1;i<=m;i++) flag[a[i]]=true;
	for(int i=1;i<=m;i++) 
	{
		if(vis[a[i]]!=tot)
		{
			dfs1(a[i]),cnt++;	
			for(int j=1;j<=m;j++)
			{
				if(flag[a[j]]&&vis[a[j]]==tot)
				{
					l[a[j]]=INT_MAX;
					for(int k=1;k<=m;k++)
					{
						if(j==k) continue;
						if(flag[a[k]]&&vis[a[k]]==tot) l[a[j]]=min(l[a[j]],dis[a[j]][a[k]]+1);
					}
					if(l[a[j]]==INT_MAX) continue;
					res=max(l[a[j]],res);
				}
			}
			for(int j=1;j<=m;j++) if(vis[a[j]]==tot) flag[a[j]]=false;
		} 
	}
	if(cnt!=2) return;
	ans=min(ans,res);
}
void dfs(int d,int lasti)
{
	if(d>m) { check(); return; }
	for(int i=lasti+1;i<=n-(m-d);i++) 
	{
		a[d]=i;
		dfs(d+1,i);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> T;
	int i,j,k;
	while(T--)
	{
		ans=INT_MAX;
		cin >> n >> m;
		for(i=1;i<=n;i++) G[i].clear();
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) dis[i][j]=INT_MAX/3;
		for(i=1;i<n;i++) cin >> j >> k,G[j].push_back(k),G[k].push_back(j),dis[j][k]=dis[k][j]=1;
		for(i=1;i<=n;i++) dis[i][i]=0;
		for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
}
