#include<bits/stdc++.h>
#define LL long long
#define P(i,s,t) for(int i=s;i<=t;++i)
#define S(i,s,t) for(int i=s;i>=t;--i)
using namespace std;
const int M=5e5+5,MM=1e6+5,N=505;
int head[M],nxt[MM],to[MM],cnt;
LL f[N][N],dis[M],w[MM],z,ans;
int c,d,n,m,q,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	memset(f,127/3,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	P(i,1,m) cin>>dis[i];
	P(i,1,n){
		cin>>x;
		P(j,1,x){
			cin>>y>>z;
			for(int u=head[y];u;u=nxt[u])
				f[i][to[u]]=w[u]+z;
			nxt[++cnt]=head[y],to[cnt]=i,w[cnt]=z,head[y]=cnt;
		}
		f[i][i]=0;
	}
	P(i,1,n) P(j,i+1,n) f[i][j]=f[j][i];
	P(k,1,n) P(i,1,n) P(j,1,n) if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j];
	
	while(q--){
		cin>>x>>y,ans=1e18;
		for(int v=head[x];v;v=nxt[v]){
			for(int u=head[y];u;u=nxt[u]){
				z=f[to[u]][to[v]]+w[u]+w[v];
				if(z<ans) ans=z;
			}
		}
		cout<<ans+dis[x]+dis[y]<<'\n';
	}

	
	return 0;
}
