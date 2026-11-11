#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define fi first
#define se second
#define mk(a,b) make_pair(a,b) 
const int maxn=1e6,N=505;
int c,n,m,q,d,w[maxn],W[N][N]; 
vector<pii >p[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			W[i][j]=1e16,W[i][i]=W[j][j]=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			for(int l=0;l<p[x].size();l++){
				int g=p[x][l].fi;
				W[i][g]=min(W[i][g],t+p[x][l].se);
				W[g][i]=W[i][g];
			}
			p[x].push_back(mk(i,t));
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				W[i][j]=min(W[i][k]+W[k][j],W[i][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<p[x].size();i++){
			int g=p[x][i].fi;
			for(int j=0;j<p[y].size();j++){
				int g2=p[y][j].fi;
				ans=min(ans,W[g][g2]+p[x][i].se+p[y][j].se);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

