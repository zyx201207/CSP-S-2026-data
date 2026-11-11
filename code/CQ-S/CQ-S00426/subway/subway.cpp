#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;//编号，线路数，地铁站数，最多线路经过数，询问数 
int w[500005];//地铁口到站厅的时间 
int k[505];//每条线路经过的站点数
vector<int> a[505],t[505];//每条线路经过的站点和时间 
int dp[505][505];//线路之间的最短路径 
vector<int> xl[500005],tim[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		xl[i].push_back(0);
		tim[i].push_back(0);
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			xl[aa].push_back(i);
			a[i].push_back(aa);
			tim[aa].push_back(tt);
			t[i].push_back(tt);
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int l=1;l<xl[i].size();l++){
			for(int r=l+1;r<xl[i].size();r++){
				dp[xl[i][l]][xl[i][r]]=dp[xl[i][r]][xl[i][l]]=min(dp[xl[i][l]][xl[i][r]],tim[i][l]+tim[i][r]);
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
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=1;i<xl[x].size();i++){
			for(int j=1;j<xl[y].size();j++){
				ans=min(ans,w[x]+w[y]+tim[x][i]+tim[y][j]+dp[xl[x][i]][xl[y][j]]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
容易发现地铁的线路少，但是站点多
所以把从站点考虑换成从线路考虑
算出每个线路之间的最短路径，便可以通过枚举起始点和终止点的线路哪些，算出答案，o(d^2q)轻轻松松 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
