#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define inf 0x3f
#define Inf 0x3f3f3f3f3f3f3f3f
const int N=1e4+5;
ll c,n,m,d,q;
ll w[N*2];
ll f[N*2][N*2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		ll x;
		cin>>x;
		w[i+n]=x;
	}
	memset(f,inf,sizeof(f));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll u,t;
			cin>>u>>t;
			f[i+m][u]=f[u][i+m]=t;
		}
	}
	
	for(int k=1;k<=m*2;k++){
		for(int i=1;i<=m*2;i++){
			for(int j=i+1;j<=m*2;j++){
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		cout<<f[u][v]+w[u+n]+w[v+n]<<"\n";
	}
	return 0;
}
