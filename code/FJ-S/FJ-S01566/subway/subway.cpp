#include <bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define endl '\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define st first
#define nd second
#define pb push_back
//#define int long long
using namespace std;
using ll=long long;
using lld=long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int M=5e5+10,N=510;
const ll inf=1e18;
int c,n,m,d,q,a,k[N];
ll w[M],t,dis[N][N],ans;
vector<int>g[N];
vector<pii>p[M];
signed main(){
	FILE("subway"),
	ios::sync_with_stdio(false),
	cin.tie(0),cout.tie(0);
	mem(dis,0x3f),cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0,cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			p[a].pb({i,t});
			for(pii v:p[a]){
				dis[i][v.st]=dis[v.st][i]=min(dis[v.st][i],t+v.nd);
			}
		}
	}
//	for(int i=1;i<=n;i++,cerr<<endl)for(int j=1;j<=n;j++)cerr<<dis[i][j]<<' ';
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)for(int j=1;j<=n;j++)
				if(j!=i&&j!=k)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
//		cerr<<q<<endl;
		int x,y;ans=inf,cin>>x>>y;
		for(pii s:p[x])for(pii t:p[y])
			ans=min(ans,dis[s.st][t.st]+s.nd+t.nd);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
