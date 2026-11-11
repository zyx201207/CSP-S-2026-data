#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int N=505,M=5e5+5;
bool st;
int c,n,m,d,q;
int W[M],p[M];
int v[M][25],w[M][25];
int dis[N][N];
void chkmn(int &x,int y){x=min(x,y);}
bool ed;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cerr<<(&st-&ed)/1024.0/1024.0;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1,a,b;j<=k;j++){
			cin>>a>>b;
			p[a]++;
			v[a][p[a]]=i;
			w[a][p[a]]=b;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p[i];j++){
			for(int k=j+1;k<=p[i];k++){
				chkmn(dis[v[i][j]][v[i][k]],w[i][j]+w[i][k]);
				chkmn(dis[v[i][k]][v[i][j]],w[i][j]+w[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				chkmn(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]>=inf) cerr<<i<<" "<<j<<" "<<dis[i][j]<<'\n';
		}
	}
	while(q--){
		int s,t;cin>>s>>t;
		int ans=inf;
		for(int i=1;i<=p[s];i++){
			for(int j=1;j<=p[t];j++){
				chkmn(ans,dis[v[s][i]][v[t][j]]+w[s][i]+w[t][j]);
			}
		}
		if(s==t){
			cout<<0<<'\n';
		}else cout<<ans+W[s]+W[t]<<'\n';
	}
//	cerr<<(&st-&ed)/1024.0/1024.0;
}
