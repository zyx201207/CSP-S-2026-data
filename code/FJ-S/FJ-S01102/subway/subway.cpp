#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=505;
const ll inf=1e18;
int n,m,d,cr[N][25][2],sz[N],p[M];
ll val[N],dis[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _,q;
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>val[i];
	for(int i=1;i<=n;i++){
		cin>>p[i];
		for(int j=1,x,y;j<=p[i];j++){
			cin>>x>>y;
			sz[x]++;
			cr[x][sz[x]][0]=i;
			cr[x][sz[x]][1]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int l=1;l<=sz[i];l++){
			for(int r=l+1;r<=sz[i];r++){
				int u=cr[i][l][0],v=cr[i][r][0];
				ll w=1ll*(cr[i][l][1]+cr[i][r][1]);
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		ll ans=inf;
		for(int i=1;i<=sz[s];i++){
			for(int j=1;j<=sz[t];j++){
				int u=cr[s][i][0],v=cr[t][j][0];
				ll w=cr[s][i][1]+cr[t][j][1];
				ans=min(ans,w+dis[u][v]);
			}
		}
		ans+=(val[s]+val[t]);
		cout<<ans<<"\n";
	}
	return 0;
}
