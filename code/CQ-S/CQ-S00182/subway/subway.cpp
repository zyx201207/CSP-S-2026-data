#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=502,M=5e5+2,K=21;
int x,n,m,d,q,w[M],k,y,tot[M],to[N][N],ans;
struct nod{int x,t;}a[M][K];map<pair<int,int>,int> mp;
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>x>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k;for(int j=1;j<=k;++j){
			cin>>x>>y;
			a[x][++tot[x]]={i,y};
		}for(int j=1;j<=n;++j)to[i][j]=1ll<<60;
		to[i][i]=0;
	}for(int i=1;i<=m;++i){
		for(int j=1;j<tot[i];++j){
			for(int g=j+1;g<=tot[i];++g){
				x=a[i][j].x,y=a[i][g].x;
				to[x][y]=min(to[x][y],a[i][j].t+a[i][g].t);
				to[y][x]=to[x][y];
			}
		}
	}for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				to[i][j]=min(to[i][j],to[i][k]+to[k][j]);
			}
		}
	}for(int i=1;i<=q;++i){
		cin>>x>>y,ans=LLONG_MAX;
		for(int j=1;j<=tot[x];++j){
			nod f=a[x][j],f2;
			for(int g=1;g<=tot[y];++g){
				f2=a[y][g];
				ans=min(ans,f.t+f2.t+to[f.x][f2.x]);
			}
		}ans+=w[x]+w[y];cout<<ans<<'\n';
	}return 0;
}
