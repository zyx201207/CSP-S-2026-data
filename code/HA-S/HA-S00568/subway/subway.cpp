#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pil pair<int,long long>
#define fi first
#define se second

const int N=510,M=5e5+10;
const ll inf=1e18;

int dlh,n,m,d,q,sz[M];
int kou[M];
ll f[N][N];
vector<pil>v[M];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>dlh>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>kou[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=inf;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		sz[i]=v[i].size();
		int x,y;
		ll val;
		for(int j=0;j<sz[i];j++){
			for(int k=j+1;k<sz[i];k++){
				x=v[i][j].fi,y=v[i][k].fi;
				val=v[i][j].se+v[i][k].se;
				f[x][y]=min(f[x][y],val);
				f[y][x]=min(f[y][x],val);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(int i=0;i<sz[x];i++){
			for(int j=0;j<sz[y];j++){
				ans=min(ans,f[v[x][i].fi][v[y][j].fi]+v[x][i].se+v[y][j].se);
			}
		}
		ans=ans+kou[x]+kou[y];
		cout<<ans<<"\n";
	}

	return 0;
}


