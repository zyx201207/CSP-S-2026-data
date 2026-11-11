#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> >adj[1000001];
long long v[1000001],sub[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(sub,0x3f,sizeof sub);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>v[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		while(k--){
			long long a,t;
			cin>>a>>t;
			adj[a].push_back({i,t});
		}
	}
	for(long long i=1;i<=m;i++){
		for(auto e1:adj[i]){
			for(auto e2:adj[i]){
				if(e1==e2){
					sub[e1.first][e2.first]=0;
					sub[e2.first][e1.first]=0;
				}
				else{
					sub[e1.first][e2.first]=min(sub[e1.first][e2.first],e1.second+e2.second);
					sub[e2.first][e1.first]=min(sub[e2.first][e1.first],e1.second+e2.second);
				}
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			for(long long k=1;k<=n;k++){
				sub[i][j]=min(sub[i][j],sub[i][k]+sub[k][j]);
			}
		}
	}
	while(q--){
		long long a,b,ans=0,crt=1e18;
		cin>>a>>b;
		ans+=v[a];
		ans+=v[b];
		for(auto e1:adj[a]){
			for(auto e2:adj[b]){
				crt=min(crt,e1.second+e2.second+sub[e1.first][e2.first]);
			}
		}
		cout<<ans+crt<<'\n';
	}
	return 0;
}
