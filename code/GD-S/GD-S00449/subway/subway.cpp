#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
struct str{
	int id;
	int t;
};
vector<str> v[500005];
int dp[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
		dp[i][i]=0;
		int x;
		cin>>x;
		while(x--){
			int y,z;
			cin>>y>>z;
			v[y].push_back({i,z});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				int x=v[i][j].id;
				int y=v[i][k].id;
				dp[x][y]=min(dp[x][y],v[i][j].t+v[i][k].t);
				dp[y][x]=min(dp[y][x],v[i][j].t+v[i][k].t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y,czs=1e18;
		cin>>x>>y;
		for(int j=0;j<v[x].size();j++){
			for(int k=0;k<v[y].size();k++){
				int xx=v[x][j].id;
				int yy=v[y][k].id;
				czs=min(czs,w[x]+w[y]+v[x][j].t+v[y][k].t+dp[xx][yy]);
			}
		}
		cout<<czs<<"\n";
	}
	return 0;
} 
