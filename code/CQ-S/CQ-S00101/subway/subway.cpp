#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,cid,d,q;
//O(d+qd^2+n^3)有一半常数。 m部分有点难以分析，无所谓 好像有上界skd  
vector<pair<int,int> >vec[500005];
long long dis[505][505];
int w[500005];
signed main(){
	//printf()
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,w;cin>>x>>w;
			vec[x].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			for(int k=j+1;k<vec[i].size();k++){
				int x=vec[i][j].first,y=vec[i][k].first;
				int l=vec[i][j].second+vec[i][k].second;
				dis[x][y]=min(dis[x][y],1ll*l);dis[y][x]=min(dis[y][x],1ll*l);
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
	while(q--){
		int u,v;
		cin>>u>>v;
		int l1=vec[u].size(),l2=vec[v].size();
		long long ans=0x3f3f3f3f3f3f3f3fll;
		for(int i=0;i<l1;i++){
			for(int j=0;j<l2;j++){
				int x=vec[u][i].first,y=vec[v][j].first;
				ans=min(ans,vec[u][i].second+vec[v][j].second+dis[x][y]);
			}
		}
	//	cout<<ans<<" "<<w[u]<<" "<<w[v]<<'\n';
		ans+=w[u]+w[v];
		cout<<ans<<'\n';
	}
	return 0;
}

