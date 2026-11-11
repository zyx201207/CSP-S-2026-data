#include<iostream>
#include<vector>
#define int long long
using namespace std;
const int N=510,M=500010,inf=2000000000000000000;
int c,n,m,d,q,w[M],f[N][N];
vector<pair<int,int>>g[M];
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=inf;
		f[i][i]=0;
	}
	for(int i=1,k,st,t;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>st>>t;
			for(auto wayc:g[st]){
				f[i][wayc.first]=min(f[i][wayc.first],wayc.second+t);
				f[wayc.first][i]=f[i][wayc.first];
			}
			g[st].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1,x,y,ans;i<=q;i++){
		cin>>x>>y;ans=inf;
		for(auto u:g[x])for(auto v:g[y]){
			ans=min(ans,f[u.first][v.first]+u.second+v.second);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
