#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
inline ll read(){
	ll n=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return n*f;
}
const int N=505;
const int M=5e5+5;
vector<pii> vec[M];
ll w[N][N];
ll wk[M];
int cid,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) wk[i]=read(); 
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),t=read();
			vec[x].push_back({i,t});
		}
	}
	memset(w,0x3f,sizeof(w));
	for(int i=1;i<=n;i++) w[i][i]=0;
	for(int x=1;x<=m;x++){
		int len=vec[x].size();
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				int u=vec[x][i].fi;
				int v=vec[x][j].fi;
				w[u][v]=w[v][u]=min(w[u][v], ll(vec[x][i].se+vec[x][j].se));
			}
		}
	} 
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(w[i][k]>=ll(1e18)) continue;
			for(int j=1;j<=n;j++){
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		ll ans=2e18;
		for(auto p1:vec[x]){
			for(auto p2:vec[y]){
				int u=p1.fi;
				int v=p2.fi;
				ans=min(ans, p1.se+p2.se+w[u][v]);
			}
		}
		ans+=wk[x]+wk[y];
		printf("%lld\n",ans);
	}
	
	return 0;
}
