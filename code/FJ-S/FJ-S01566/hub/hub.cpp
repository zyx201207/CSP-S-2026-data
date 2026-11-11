#include <bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define endl '\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define st first
#define nd second
//#define int long long
using namespace std;
using ll=long long;
using lld=long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int N=4010+10,K=4010,inf=1e9;
int c,t,n,p,dis[N],vis[N],cnt,kc,ans;
vector<int>g[N];
void dfs1(int u,int fa,int k){
	vis[u]=1;
	for(int v:g[u])
		if(v!=fa&&(k>>(v-1)&1))
			dfs1(v,u,k);
}
int que[N],hd,tl;
void solve(){
	cin>>n>>p,ans=inf;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].pb(v),g[v].pb(u);
	}
	for(int k=1;k<=(1<<n)-1;k++){
		int maxd=0;kc=cnt=tl=0,hd=1,mem(vis,0),mem(dis,0x3f);
		for(int i=1;i<=n;i++)
			if((k>>(i-1)&1)){
				if(++kc>p){
					maxd=inf;
					break;
				}
				if(!vis[i]){
					if(++cnt>=3){
						maxd=inf;
						break;
					}
					dfs1(i,0,k);
				}
				dis[i]=0,vis[i]=1,que[++tl]=i;
			}
		while(hd<=tl){
			int u=que[hd++];
			for(int v:g[u])if(!vis[v])
				que[++tl]=v,dis[v]=dis[u]+1,vis[v]=1;
		}
		for(int i=1;i<=n;i++)maxd=max(maxd,dis[i]);
//		cerr<<k<<' '<<maxd<<endl;
		ans=min(ans,maxd);
	}
	cout<<ans<<endl;
}
signed main(){
	FILE("hub"),
	ios::sync_with_stdio(false),
	cin.tie(0),cout.tie(0);
	for(cin>>c>>t;t--;solve());
	return 0;
}
