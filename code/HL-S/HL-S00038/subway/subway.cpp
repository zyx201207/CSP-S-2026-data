#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5,INF=1e18+7;
int TestCount,n,m,d,Q;
int dis[N][N];
int w[M];
vector<pair<int,int> > s[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>TestCount>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			s[x].push_back(make_pair(i,y));
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<s[i].size();j++){
			for(int k=0;k<j;k++){
				int x=s[i][j].first,y=s[i][k].first,z=s[i][j].second+s[i][k].second;
				dis[x][y]=min(dis[x][y],z);
				dis[y][x]=dis[x][y];
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
	
	for(int T=1;T<=Q;T++){
		int X,Y;
		cin>>X>>Y;
		int ans=INF;
		for(pair<int,int> i:s[X]){
			for(pair<int,int> j:s[Y]){
				int x=i.first,y=j.first;
				ans=min(i.second+dis[x][y]+j.second,ans);
			}
		}
		cout<<ans+w[X]+w[Y]<<'\n';
	}
	return 0;
}