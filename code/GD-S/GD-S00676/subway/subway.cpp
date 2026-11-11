#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
const int N=5e5+20,inf=1e18;
vector<pair<int,int> > p[N];
int tid,n,m,d,q,w[N];
int f[520][520];
signed main()
{
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>tid>>n>>m>>d>>q;
	fo(i,1,m)cin>>w[i];
	fo(i,1,n)
	{
		int k,a,t;
		cin>>k;
		while(k--)
		{
			cin>>a>>t;
			p[a].push_back({i,t});
		}
	}
	fo(i,1,n)fo(j,1,n)f[i][j]=inf;
	fo(i,1,n)f[i][i]=0;
	fo(i,1,m)
	{
		int len=p[i].size();
		fo(e1,0,len-1)
			fo(e2,e1+1,len-1)
			{
				int v1=p[i][e1].first,t1=p[i][e1].second;
				int v2=p[i][e2].first,t2=p[i][e2].second;
				f[v1][v2]=min(f[v1][v2],t1+t2);
				f[v2][v1]=min(f[v2][v1],t1+t2);
			}
	}
	//du[i(1~m)]<=d<=20
	fo(k,1,n)
		fo(i,1,n)
			fo(j,1,n)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int u,v,ans=inf;cin>>u>>v;
		for(auto i:p[u])
			for(auto j:p[v])
				ans=min(ans,f[i.first][j.first]+i.second+j.second);
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}//40min
