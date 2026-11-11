#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int>>bel[500005];//每个站的线路经过，以及距离 
vector<pair<int,int>>g[505];
/*建图方式
不妨把每个线路看成一个点 
*/ 
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			bel[a].push_back({i,t});
		}
	}
	
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<bel[i].size();j++){
			for(int k=j+1;k<bel[i].size();k++){
				g[bel[i][j].first].push_back({bel[i][k].first,bel[i][j].second+bel[i][k].second});
				g[bel[i][k].first].push_back({bel[i][j].first,bel[i][j].second+bel[i][k].second});
				dis[bel[i][j].first][bel[i][k].first]=dis[bel[i][k].first][bel[i][j].first]=min(dis[bel[i][k].first][bel[i][j].first],bel[i][j].second+bel[i][k].second);
				
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		} 
	}
	//vector<int>my;
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for(int i=0;i<bel[u].size();i++){
			for(int j=0;j<bel[v].size();j++){
				ans=min(ans,dis[bel[u][i].first][bel[v][j].first]+bel[u][i].second+bel[v][j].second);
			}
		}
		cout<<w[u]+w[v]+ans<<endl;
		//my.push_back(w[u]+w[v]+ans);
	}
//	fclose(stdin);
//	freopen("subway7.ans","r",stdin);
//	int x;
//	int cur=0;
//	while(cin>>x){
//		if(x!=my[cur++]) {
//			cout<<"Wrong anwer";
//			return 0;
//			
//		}
//	} 
//	cout<<"Accept";
} 
