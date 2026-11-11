#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N=505;
const int M=5*1e5+5;
const int INF=1e18;
int cid,n,m,d,q;
int w[M],f[N][N];
vector<pair<int,int> >ed[N+M];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=INF;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to,t;
			cin>>to>>t;
			ed[to].push_back({m+i,t});
			ed[m+i].push_back({to,t});
		}
	}
	//edge station_id 1~m;rail_id m+1~m+n
	for(int i=1;i<=n;i++){
		for(auto from_edge:ed[m+i]){//rail->station
			int id=from_edge.first;
			for(auto to_edge:ed[id]){//station->rail
				int j=to_edge.first-m;
				f[i][j]=f[j][i]=min(f[i][j],from_edge.second+to_edge.second);
			}
		}
	}
	//cout<<f[1][2]<<endl;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//cout<<"debug:"<<i<<"->"<<k<<"->"<<j<<' '<<f[i][j]<<' ';
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
				//cout<<f[i][j]<<'\n';
			}
		}
	}
	//cout<<f[1][2]<<endl;
	while(q--){
		int x,y,ans=INF;
		cin>>x>>y;
		for(auto from_edge:ed[x]){
			int i=from_edge.first;
			for(auto to_edge:ed[y]){
				int j=to_edge.first;
				ans=min(ans,w[x]+w[y]+f[i-m][j-m]+from_edge.second+to_edge.second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
