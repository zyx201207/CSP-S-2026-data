#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define per(i,r,l) for(int i=(r),i##end=(l);i>=i##end;--i)
using namespace std;
const int maxn=5e5+10,maxm=500+10,mod=998244353;
inline int ksm(int x,int k,int mod=mod){
	int ans=1;
	for(;k;k>>=1,x=x*x%mod) if(k&1) ans=ans*x%mod;
	return ans;
}

int testid,n,m,d,q,w[maxn],f[maxm][maxm];
vector<pair<int,int>> e[maxn];

signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>testid>>n>>m>>d>>q;
	rep(i,1,n) rep(j,1,n) f[i][j]=1e18;
	rep(i,1,n) f[i][i]=0;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n){
		int k,u,v,o;
		cin>>k;
		rep(j,1,k) cin>>u>>o,e[u].push_back(make_pair(i,o));
	}
	rep(i,1,m){
		int k=e[i].size();
		rep(x,0,k-1) rep(y,x+1,k-1) f[e[i][x].first][e[i][y].first]=
			min(f[e[i][x].first][e[i][y].first],e[i][x].second+e[i][y].second);
	}
	rep(i,1,n) rep(j,1,n) f[i][j]=f[j][i]=min(f[i][j],f[j][i]);
	rep(k,1,n) rep(i,1,n) rep(j,1,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	rep(i,1,q){
		int x,y,ans=1e18;
		cin>>x>>y;
		rep(o,0,e[x].size()-1) rep(p,0,e[y].size()-1) ans=min(ans,
			e[x][o].second+e[y][p].second+f[e[x][o].first][e[y][p].first]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
