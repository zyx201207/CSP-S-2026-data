#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,M=5e5+10;
int C,n,m,D,q,W[M],d[N][N];
vector<pair<int,int> > v[M];
signed main(){
//	system("fc subway.out subway7.ans"); return 0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x,y,z;
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y>>z;
			v[y].push_back(make_pair(i,z));
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) d[i][j]=1e18;
	for(int i=1;i<=m;i++){
		for(auto it1:v[i]){
			for(auto it2:v[i]){
				int x=it1.first,y=it2.first;
				d[x][y]=min(d[x][y],it1.second+it2.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int ans=2e18;
		cin>>x>>y;
		for(auto it1:v[x]){
			for(auto it2:v[y]){
				int k1=it1.first,k2=it2.first;
				ans=min(ans,d[k1][k2]+it1.second+it2.second);
			}
		}
		cout<<ans+W[x]+W[y]<<'\n';
	}
	return 0;
}
