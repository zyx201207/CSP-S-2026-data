#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,NM=505+2e4;
int c,n,m,d,q;
int w[N];
ll f[N][NM];//f[i][j] i->bian j->bian+dian
vector<int> e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		memset(f[i],0x3f,sizeof(f[i]));
		f[i][i]=0;
	}
	int INF=f[1][1];
	for(int i=1;i<=n;i++){
		int k,a;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>f[i][n+a];
			e[a].push_back(i);
		}
	}
	for(int k=n+m;k>=1;k--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(f[i][k]==INF||f[j][k]==INF||i==k||j==k) continue;
				 f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[j][k]);
			}
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(auto u:e[x]){
			for(auto v:e[y]){
				//if(f[u][v]==INF) continue;
				ans=min(ans,f[u][n+x]+f[v][n+y]+f[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	
	return 0;
}
