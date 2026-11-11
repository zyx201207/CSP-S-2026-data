#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=500010;
const ll Inf=1ll<<58;
int CID,n,m,d,q,w[M],h[M],tot;
ll f[N][N];
struct subway{
	int x,t,nxt;
}s[M];
void add(int i,int x,int t)
{
	s[++tot]=(subway){x,t,h[i]};
	h[i]=tot;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>CID>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			add(a,i,t);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) f[i][j]=Inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=h[i];j;j=s[j].nxt)
		{
			for(int k=s[j].nxt;k;k=s[k].nxt)
			{
				f[s[j].x][s[k].x]=f[s[k].x][s[j].x]=s[j].t+s[k].t;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=Inf;
		for(int i=h[x];i;i=s[i].nxt)
		{
			for(int j=h[y];j;j=s[j].nxt)
			{
				ans=min(ans,f[s[i].x][s[j].x]+s[i].t+s[j].t);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
