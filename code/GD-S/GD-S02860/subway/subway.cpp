#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=5e5+5;
using ll=long long;
using pii=pair<int,ll>;
int c,n,m,d,q,w[M];
long long f[N][N];
vector<pii>z[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("1.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int a,t;
			cin>>a>>t;
			z[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:z[i]){
			for(auto k:z[i]){
				if(j==k)continue;
				f[j.first][k.first]=min(f[j.first][k.first],j.second+k.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
//			cout<<f[i][j]<<" ";
		}//cout<<"\n";
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(auto i:z[u]){
			for(auto j:z[v]){
				ans=min(ans,f[i.first][j.first]+i.second+j.second);
			}
		} 
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
