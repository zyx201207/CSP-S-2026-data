#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pil pair<int,ll>
#define zzz ios::sync_with_stdio(0),cin.tie(0)
#define e_b emplace_back
using namespace std;
const int N=5e3+5;
const int inf=1e9;
int n;
vector<int>g[N];
ll d,a[N];
int dis[N],ct[N];
bool vis[N];
queue<int>q;
int dij(int st){
	int re=0;
	for(int i=1;i<=n;i++)dis[i]=inf,vis[i]=ct[i]=0;
	dis[st]=0;q.push(st);ct[st]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int v:g[u]){
			if(dis[v]>dis[u]+1)dis[v]=dis[u]+1,ct[v]=0;
			if(dis[v]==dis[u]+1)ct[v]+=ct[u],q.push(v);
		}
	}
	for(int i=1;i<=n;i++)if(ct[i]==2)re++;//cout<<st<<' '<<i<<'\n';
	return re;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i],g[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(abs(a[i]-a[j])<=d)
				g[i].e_b(j);
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=1ll*dij(i);
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	zzz;int c,T;cin>>c>>T;
	while(T--)solve();
}

