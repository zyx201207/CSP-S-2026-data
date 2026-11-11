#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,t,cur,st,ed;
int w[500005];
int dis[505][505];
vector<pair<int,int> > id[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,pos,val;j<=k;j++){
			cin>>pos>>val;
			id[pos].push_back(make_pair(i,val));
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int x=1;x<=m;x++){
		int k=id[x].size();
		for(int i=0;i<k;i++){
			for(int j=i+1;j<k;j++){
				dis[id[x][i].first][id[x][j].first]=dis[id[x][j].first][id[x][i].first]=id[x][i].second+id[x][j].second;
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
	while(t--){
		cin>>st>>ed;
		int ans=1e18,n1=(int)(id[st].size()),n2=(int)(id[ed].size());
		for(int i=0;i<n1;i++){
			for(int j=0;j<n2;j++){
				ans=min(ans,id[st][i].second+id[ed][j].second+dis[id[st][i].first][id[ed][j].first]);
			}
		}
		cout<<ans+w[st]+w[ed]<<'\n';
	}
	return 0;
}

