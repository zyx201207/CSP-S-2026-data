#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
int w[N],dis[N][N],a[N],b[N];
bool vis[N];
struct node{
	int u,t;
};
vector<node> bao[505];
int dp[5005][5005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
//	if(7<=c&&c<=11){
		memset(dp,0x3f,sizeof(dp));
		while(n--){
			int k;
			cin>>k;
			for(int i=1;i<=k;i++){
				cin>>a[i]>>b[i];
				for(int j=1;j<i;j++) dp[a[i]][a[j]]=dp[a[j]][a[i]]=min(dp[a[i]][a[j]],b[i]+b[j]);
			}
//				int a1,t1,a2,t2;
//				cin>>a1>>t1>>a2>>t2;
//				dp[a1][a2]=min(t1+t2,dp[a1][a2]),dp[a2][a1]=min(t1+t2,dp[a2][a1]);
//				cout<<dp[a1][a2]<<" ";
//				a[a1].push_back({a2,t1+t2}),a[a2].push_back({a1,t1+t2});
//			}
		}
//		for(int i=1;i<=n;i++) dp[i][i]=0;
		for(int k=1;k<=1000;k++) for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dp[x][y]+w[x]+w[y]<<"\n";
		}
//	}else if(12<=c&&c<=19){
//		
//	}else{
		
//		memset(dis,0x7f,sizeof(dis));
//		
//		while(q--){
//			int x,y;
//			cin>>x>>y;
//			if(vis[x]) cout<<dis[x][y];
//			else dijkstra
//		}
//	}
	return 0;
}
/*

*/
