#include <bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=510,M=500010,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[M],dis[N][N];
vector <pr> e[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k,p,c;cin>>k;
		while(k--){
			cin>>p>>c;
			for(pr k:e[p]) dis[k.fi][i]=dis[i][k.fi]=min(k.se+c,dis[i][k.fi]);
			e[p].push_back(mp(i,c));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		for(pr a:e[x]) for(pr b:e[y]) ans=min(ans,dis[a.fi][b.fi]+a.se+b.se);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

