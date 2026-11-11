#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int cnt[N];
#define xll __int128
xll x[N],m;
int n;
xll dis[N];
inline xll abs(xll h)
{
	return h>0?h:-h;
}
void bfs(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	queue<int> q;
	q.push(s);
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v=u+1;v<=n;v++)
		{
			if(abs(x[u]-x[v])>m||dis[v]<dis[u]+1)
				continue;
			if(dis[v]==dis[u]+1)
				cnt[v]+=cnt[u];
			else if(dis[v]>dis[u]+1)
				cnt[v]=cnt[u];
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
}
void solve()
{
	int ans=0;
	long long tmp;
	cin>>n>>tmp;
	m=tmp;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		x[i]=tmp;
	}
	vector<int> g[N];
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<":";
//		for(int j=i+1;j<=n;j++)
//			if(abs(x[i]-x[j])<=m)
//				cout<<j<<" ";
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=1;j<=n;j++)
			if(cnt[j]==2) ans++;
//		for(int j=1;j<=n;j++)
//			cout<<cnt[j]<<" ";
//		cout<<"\n";
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
