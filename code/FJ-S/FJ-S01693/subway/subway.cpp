#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long INF=1e18;
long long w[N];
long long dis[505][505];
vector<pair<int,long long>>b[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=INF;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			long long y;
			cin>>x>>y;
			b[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:b[i]){
			for(auto k:b[i]){
				dis[j.first][k.first]=min(dis[j.first][k.first],j.second+k.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=INF;
		for(auto j:b[x]){
			for(auto k:b[y]){
				ans=min(ans,w[x]+w[y]+j.second+k.second+dis[j.first][k.first]);
			}
		}
		cout<<ans<<'\n';
	}
}
