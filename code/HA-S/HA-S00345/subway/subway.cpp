#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x7f7f7f7f7f7f7f
#define maxn 500005
#define Maxn 505

int c,n,m,d,q;
ll w[maxn];
vector<int>rec[Maxn];
vector<int>e[maxn];
int p[maxn][Maxn];
ll vis[Maxn];
ll f[Maxn][Maxn];

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	init();
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		for(int j=1;j<=s;j++){
			int u;
			ll t;
			cin>>u>>t;
			rec[i].push_back(u);
			e[u].push_back(i);
			p[u][i]=t;
		}
	}
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[j]=inf;
		}
		for(int v:rec[i]){
			for(int j:e[v]){
				if(j!=i){
					vis[j]=min(vis[j],(ll)(p[v][j]+p[v][i]));
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(vis[j]!=inf&&i!=j){
				f[i][j]=vis[j];
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
		int u,v;
		cin>>u>>v;
		ll ans=inf;
		for(int i:e[u]){
			for(int j:e[v]){
				ans=min(ans,f[i][j]+w[u]+w[v]+(ll)(p[u][i]+p[v][j]));
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
