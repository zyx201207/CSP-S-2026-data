#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
vector<PII> xian[N];
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,len;i<=n;i++){
		cin>>len;
		while(len--){
			int x,t;
			cin>>x>>t;
			xian[x].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int x=1;x<=m;x++){
		for(int i=0;i<xian[x].size();i++){
			for(int j=i+1;j<xian[x].size();j++){
				dis[xian[x][i].first][xian[x][j].first]=xian[x][i].second+xian[x][j].second;
				dis[xian[x][j].first][xian[x][i].first]=xian[x][i].second+xian[x][j].second;
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
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
//		}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<xian[x].size();i++){
			for(int j=0;j<xian[y].size();j++){
				int x1=xian[x][i].first,t1=xian[x][i].second;
				int x2=xian[y][j].first,t2=xian[y][j].second;	
				int res=dis[x1][x2]+t1+t2;
//				cout<<x1<<" "<<x2<<" "<<t1<<" "<<t2<<"\n";
				ans=min(ans,res);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
