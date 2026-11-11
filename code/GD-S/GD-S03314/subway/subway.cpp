#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5,N=500;
int c,n,m,d,q;
ll a[M+7];
vector<pair<int,ll>> zhan[M+7];
long long floyd[N+7][N+7];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u;
			ll v;
			cin>>u>>v;
			zhan[u].push_back({i,v});
		}
	}
	memset(floyd,0x3f,sizeof floyd);
	for(int i=1;i<=m;i++){
		for(auto j:zhan[i]){
			for(auto k:zhan[i]){
				if(j.first==k.first) continue;
				floyd[j.first][k.first]=min(floyd[j.first][k.first],j.second+k.second);
//				cout<<i<<":"<<j.first<<" "<<k.first<<" "<<j.second+k.second<<"\n";
			}
		}
	}
	for(int i=1;i<=n;i++) floyd[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				floyd[j][i]=floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
			}
		}
	}
//	cout<<floyd[1][2]<<"\n"; 
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto i:zhan[u]){
			for(auto j:zhan[v]){
				ans=min(floyd[i.first][j.first]+i.second+j.second,ans);
			}
		}
		cout<<ans+a[u]+a[v]<<"\n";
	}
	return 0;
}
