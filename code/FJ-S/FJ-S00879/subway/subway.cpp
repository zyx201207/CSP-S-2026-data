#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5; 
const int inf=1e18;
int c,n,m,d,qt,h[N],to[N],nxt[N],val[N],cnt=0;
int nd=0,e[505][505]; 
void add(int u,int v,int w){
	to[++cnt]=v;nxt[cnt]=h[u];h[u]=cnt;val[cnt]=w;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qt;
	for(int i=1;i<=m;i++){
		int w;cin>>w;
		add(i,m+i,w);
		add(m+i,i,w);
	}
	nd=m*2;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		nd++;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			add(nd,a+m,t);
			add(a+m,nd,t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		e[i][i]=0;
	}
	for(int u=m*2+1;u<=nd;u++){
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(v!=u){
				for(int j=h[v];j;j=nxt[j]){
					int w=to[j];
					if(m*2+1<=w&&w<=nd){
						e[u-m*2][w-m*2]=min(e[u-m*2][w-m*2],val[i]+val[j]);
					}
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	while(qt--){
		int x,y;cin>>x>>y;
		int	xx=to[h[x]],yy=to[h[y]];
		int ans=inf;
		for(int i=h[xx];i;i=nxt[i]){
			for(int j=h[yy];j;j=nxt[j]){
				int u=to[i],v=to[j];
				if(m*2+1<=u&&u<=nd&&m*2+1<=v&&v<=nd){
					ans=min(ans,e[u-m*2][v-m*2]+val[i]+val[j]);
				}
			}
		}
		cout<<ans+val[h[x]]+val[h[y]]<<'\n';
	}
	return 0;
} 
