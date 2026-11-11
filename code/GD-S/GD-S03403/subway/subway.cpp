#include <bits/stdc++.h>
using namespace std;
const long long N=1003,M=503,MAXN=0x3f3f3f3f3f3f3f3f;
long long c,n,m,d,q,w[N],cnt,sum,ti[M][N],kk[M],ans,us[N];
bool vis[N];
vector<int> s[N];
void dfs(int now,int to)
{
	if(now==to)
	{
		cnt=us[to];
	}
	vis[now]=true;
	for(int i=0;i<s[now].size();i++)
	{
		int u=s[now][i],uu=us[now]+ti[now][u];
		if(uu<us[u])
		{
			us[u]=uu;
			dfs(u,to);
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>kk[i];
		if(kk[i]==2)
		{
			int x1,x2,x3,x4;
			cin>>x1>>x2>>x3>>x4;
			s[x1].push_back(x3);
			s[x3].push_back(x1);
			ti[x1][x3]=ti[x3][x1]=x2+x4;
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(us,MAXN,sizeof(us) );
		int x,y;
		cin>>x>>y;
		sum=w[x]+w[y];
		us[x]=0;
		dfs(x,y);
		ans=cnt+sum;
		cout<<ans<<"\n";
	}
	return 0;
}
