#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll=long long;
using pii=pair<int,int>;

const int M=5e5+5,N=505;
const ll INF=1e18+5;
int c,n,m,d,q,w[M],k[N];
vector<pii> ve[N];

bool vis1[M],vis2[M];
vector<int> ve1;

ll dis[5005][5005];

void solve(){
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			dis[i][j]=INF;
		}
	}

	for(int i=1;i<=n;++i){
		for(int j=0;j<k[i];++j){
			for(int l=j+1;l<k[i];++l){
				dis[ve[i][j].fi][ve[i][l].fi]=
				dis[ve[i][l].fi][ve[i][j].fi]=
				min(dis[ve[i][j].fi][ve[i][l].fi],1ll*ve[i][j].se+ve[i][l].se);
			}
		}
	}
/*
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			cout<<dis[i][j]<<" \n"[j==m];
		}
	}*/

	for(int k=1;k<=m;++k){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}

	while(q--){
		int x,y;cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
}
/*
void solveN(){
	for(int i=0;i<k[1];++i){
		vis1[ve[1][i]]=true;
	}
	for(int i=0;i<k[2];++i){
		vis2[ve[2][i]]=true;
	}
	for(int i=1;i<=m;++i){
		if(vis1[i]&&vis2[i]){
			ve1.push_back({})
		}
	}
}*/

void input(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int a,t;cin>>a>>t;
			ve[i].push_back({a,t});
		}
	}
/*
	if(c<=11){
		solve();
	}else if(c==20||c==21){
		solveN();
	}*/
	solve();
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	while(t--) input();

	return 0;
}