#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 33;
int n,m,d,T,c,x[N],vis[N],dis[N],xo[N];
vector<int>v[N];
queue<int>q;
int spfa(int s)
{
	memset(dis,0x3f,sizeof dis);
	memset(xo,0,sizeof xo);
	dis[s]=0;
	vis[s]=1;
	xo[s]=1;
	q.push(s);
	while(!q.empty())
	{
	  int now=q.front();
	  q.pop();
	  vis[now]=0;
	  for(int i:v[now])
	    if(dis[i]>dis[now]+1)
	    {
	      dis[i]=dis[now]+1;
	      xo[i]=xo[now];
	      if(!vis[i]) q.push(i),vis[i]=1;
		}
		else if(dis[i]==dis[now]+1) xo[i]++;
	}
	int res=0;
	for(int i=1;i<=n;i++) res+=(xo[i]==2);
	return res;
}
void solve()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	  ans+=spfa(i);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--)
	{
	  cin>>n>>d;
	  memset(x,0,sizeof x);
	  for(int i=1;i<=n;i++) v[i].clear();
	  for(int i=1;i<=n;i++)
	    cin>>x[i];
	  for(int i=1;i<=n;i++)
	    for(int j=i+1;j<=n;j++)
	      if(abs(x[j]-x[i])<=d)
	        v[i].push_back(j);
	  solve();
	}
	return 0;
}