#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+3;
int c;
int n,m,d,q;
int pos,t;
int k[N],x,y;
int z[M];
struct dd{int v,w;};
long long f[N][N];
vector<dd>a[M],l[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(f,0x3f,sizeof(f));
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>z[i];
	for(int i=1; i<=n; i++){
		cin>>k[i];
		f[i][i]=0;
		for(int j=0; j<k[i]; j++){
			cin>>x>>y;
			l[i].push_back({x,y});
			a[x].push_back({i,y});
		}
	}
	for(int u=1; u<=n; u++){
		for(int j=0; j<k[u]; j++){
			int i=l[u][j].v,uw=l[u][j].w;
			int dd=a[i].size();
			for(int p=0; p<dd; p++){
				int v=a[i][p].v,vw=a[i][p].w;
				if(u==v)continue;
				f[u][v]=min(f[u][v],1ll*(uw+vw));
			}
		}
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			if(k==i)continue;
			for(int j=1; j<=n; j++){
				if(k==j||i==j)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
			}
		}		
	}
	while(q--){
		cin>>x>>y;
		long long ans=1e18;
		for(int i=0; i<a[x].size(); i++){
			int u=a[x][i].v,uw=a[x][i].w;
			for(int j=0; j<a[y].size(); j++){
				int v=a[y][j].v,vw=a[y][j].w;
				ans=min(ans,f[u][v]+1ll*(uw+vw));
			}
		}
		cout<<ans+1ll*z[x]+1ll*z[y]<<"\n";
	}
	return 0;
}
