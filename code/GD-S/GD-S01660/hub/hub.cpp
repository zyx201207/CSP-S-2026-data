#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define REP(i,x,y) for(int i=(x);i>=(y);i--)
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
const int N=4003;
const int INF=1e9;
int testId,T,n,m,sz[N],mx[N];
int f[N][12],dep[N],dp[N][N],g[N];
vector<int> v[N];
void dfs(int x,int fa){ sz[x]=1;
	f[x][0]=fa; dep[x]=dep[fa]+1; mx[x]=1;
	rep(i,1,11) f[x][i]=f[f[x][i-1]][i-1];
	for(int y:v[x]){
		if(y==fa) continue;
		dfs(y,x);
		mx[x]=max(mx[x],mx[y]+1);
	}
	dp[x][1]=0; dp[x][0]=INF;
	for(int y:v[x]){
		if(y==fa) continue;
		rep(j,0,sz[x]) g[j]=dp[x][j];
		sz[x]+=sz[y];
		rep(j,0,sz[x]){
			dp[x][j]=INF;
			rep(k,0,min(j,sz[y])){
				dp[x][j]=min(dp[x][j],max(g[j-k],dp[y][k]));
			}
		}
	}
	dp[x][0]=mx[x];
	rep(j,sz[x]+1,m) dp[x][j]=0;
}
int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	REP(i,11,0){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	}
	if(x==y) return x;
	REP(i,11,0){
		if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
inline int Dist(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void Main(){
	cin>>n>>m;
	rep(i,1,n) v[i].clear();
	int x,y;
	rep(i,1,n-1){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans=INF;
	rep(i,1,n){
		dfs(i,0);
		rep(A,1,n){
			int ANS=dp[A][m];
			rep(j,1,n){
				if(LCA(j,A)==A) continue;
				ANS=max(ANS,Dist(A,j));
			}
			ans=min(ans,ANS);
		}
		rep(A,1,n){ if(A==i) continue;
			rep(B,1,n){ if(B==i||B==A) continue;
				int ANS=INF;
				rep(l,1,m-1){
					ANS=min(ANS,max(dp[A][l],dp[B][m-l]));
				}
				rep(j,1,n){
					if(LCA(j,A)==A||LCA(j,B)==B) continue;
					ANS=max(ANS,min(Dist(j,A),Dist(j,B)));
				}
				ans=min(ans,ANS);
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	fastIO;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>testId>>T;
	while(T--) Main();
	return 0;
}
