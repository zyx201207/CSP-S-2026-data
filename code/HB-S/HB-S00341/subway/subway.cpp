#include<iostream>
#include<utility>
#include<vector>
using namespace std;

int cid,n,m,d,q;
long long dis[505][505],w[500005];
vector<pair<int,long long> > v[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			v[a].emplace_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=2e18;
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int siz=v[i].size();
		for(int j=0;j<siz-1;j++){
			for(int k=1;k<siz;k++){
				int a=v[i][j].first,b=v[i][k].first;
				long long dix=v[i][j].second+v[i][k].second;
				dis[a][b]=min(dis[a][b],dix);
				dis[b][a]=min(dis[b][a],dix);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		long long ans=2e18;
		cin>>a>>b;
		int sia=v[a].size(),sib=v[b].size();
		for(int i=0;i<sia;i++){
			for(int j=0;j<sib;j++) ans=min(ans,dis[v[a][i].first][v[b][j].first]+v[a][i].second+v[b][j].second);
		}
		cout<<ans+w[a]+w[b]<<"\n";
	}
	return 0;
}
