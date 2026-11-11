#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=505;
const ll inf=1e16;
int a[N];
ll d[M][M];
vector<pair<int,ll>>e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,D,q;
	cin>>n>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				d[i][j]=0;
			}else{
				d[i][j]=inf;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			ll y;
			cin>>x>>y;
			e[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=j+1;k<e[i].size();k++){
				int x=e[i][j].first,y=e[i][k].first;
				ll c=e[i][j].second+e[i][k].second;
				d[x][y]=min(d[x][y],c);
				d[y][x]=min(d[y][x],c);
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
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				int tx=e[x][i].first;
				int ty=e[y][j].first;
				ll res=d[tx][ty]+e[x][i].second+e[y][j].second;
				res=res+a[x]+a[y];
				ans=min(ans,res);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
