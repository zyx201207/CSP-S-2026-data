#include<bits/stdc++.h>
using namespace std;

const int M=5e5;
const int N=500;
const long long inf=1e18+7;

int C,n,m,d,q;
int w[M+5];
int k[N+5];
int a[N+5][M+5];
long long mp[N+5][N+5]; 
vector<int> h[M+5];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(mp,0x3f3f3f3f,sizeof(mp));
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			h[x].push_back(i);
			a[i][x]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int u:h[i]){
			for(int v:h[i]){
				if(u==v) continue;
				mp[u][v]=min(mp[u][v],(long long)a[u][i]+a[v][i]);
				mp[v][u]=min(mp[u][v],(long long)a[u][i]+a[v][i]);
			}
		}
	}
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(k==j||i==j) continue;
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		long long ans=inf;
		cin>>x>>y;
		for(int u:h[x]){
			for(int v:h[y]){
				ans=min(ans,(long long)mp[u][v]+a[u][x]+a[v][y]+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
