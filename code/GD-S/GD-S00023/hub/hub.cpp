#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
const int M=501;
int c,T,n,k;
bool f[N],vis[N];
int dis[M][M];
vector<int> a[N];
int ge(int x)	{
	int cnt=0;
	while(x)	{
		if(x&1)	++cnt;
		x/=2;
	}
	return cnt;
}
void dfs(int x)	{
	if(vis[x])	return;
	vis[x] =1;
	for(int i=0;i<(int)a[x].size();i++)	{
		if(f[a[x][i]])	dfs(a[x][i]);
	}
}
int ans;
void cintie()	{
	cin>>n>>k;
	for(int i=1;i<=n;i++)	a[i].clear();
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			if(i!=j)	dis[i][j] = 0x3f3f3f3f3f3f3f3f;
			else dis[i][j] =0;
		}
	}
	for(int i=1;i<n;i++)	{
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
		dis[x][y]=dis[y][x]=1;
	}
	for(int k=1;k<=n;k++)	{
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=n;j++)	dis[i][j] =min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	ans =LLONG_MAX;
	for(int i=0;i<(1LL<<n);i++)	{
		int g=ge(i);
		if(g!=k)	continue;
		for(int j=1;j<=n;j++)	f[j] =vis[j] =0;
		for(int j=0;j<n;j++)	{
			if(i&(1LL<<j))	f[j+1] =1;
		}
		int now=0;
		for(int j=1;j<=n;j++)	{
			if(f[j] && !vis[j])	{
				dfs(j);
				++now;
			}
		}
		if(now >2)	continue;
		int maxn =LLONG_MIN;
		for(int j=1;j<=n;j++)	{
			if(f[j])	continue;
			int now=LLONG_MAX;
			for(int k=1;k<=n;k++)	{
				if(!f[k])	continue;
				now=min(now,dis[j][k]);
			}
			maxn=max(maxn,now);
		}
		ans =min(ans,maxn);
	}
	cout<<ans<<'\n';
} 
signed main()	{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c;
	for(cin>>T;T--;)		cintie();
	return 0;
}
