#include<bits/stdc++.h>
#define ll long long
#define oo 100000000000000
#define fir first
#define sec second
#define pil pair<int,long long>
#define mkp make_pair
using namespace std;
const int M=5e5+10,N=505,D=22;
ll w[M],f[N][N];
int cnt[M];
pil ro[M][D];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){int k;cin>>k;
		for(int j=1;j<=k;j++){int u;ll x;cin>>u>>x;ro[u][++cnt[u]]=mkp(i,x);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=oo;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){int u=ro[i][j].fir,v=ro[i][k].fir;ll W=ro[i][j].sec+ro[i][k].sec;
				f[u][v]=min(f[u][v],W);f[v][u]=min(f[v][u],W);
			}
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){int s,t;cin>>s>>t;ll ans=oo;
		for(int j=1;j<=cnt[s];j++){
			for(int k=1;k<=cnt[t];k++){ll W=w[s]+w[t]+ro[s][j].sec+ro[t][k].sec+f[ro[s][j].fir][ro[t][k].fir];
				ans=min(ans,W); 
			}
		}cout<<ans<<'\n';
	}
	return 0;
}

