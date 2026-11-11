#include<bits/stdc++.h>
#define int long long
//#define endl "\n"
using namespace std;
struct node{
	int v,w;
};
//int w2[510][500010];
vector<node>su[500510];
int dp[510][510];
int w[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
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
			su[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dp[i][j]=LLONG_MAX/2;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<su[i].size();j++){
			for(int k=0;k<su[i].size();k++){
				if(j==k)continue;
				dp[su[i][j].v][su[i][k].v]=min(dp[su[i][j].v][su[i][k].v],su[i][j].w+su[i][k].w);
				dp[su[i][k].v][su[i][j].v]=min(dp[su[i][k].v][su[i][j].v],su[i][j].w+su[i][k].w);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<su[i].size();j++){
//			cout<<su[i][j].w<<" ";
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n;k++){//жа 
		for(int i=1;i<=n;i++){//Ц№ 
			for(int j=1;j<=n;j++){//же 
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=LLONG_MAX/2,w_1=LLONG_MAX/5,w_2=LLONG_MAX/5;;
		for(int j=0;j<su[x].size();j++){
			for(int k=0;k<su[y].size();k++){
				int v1=su[x][j].v,v2=su[y][k].v;
				int w1=su[x][j].w,w2=su[y][k].w;
//				ans=min(ans,dp[v1][v2]);
//				cout<<ans+w_1+w_2<<" "<<dp[v1][v2]+w1+w2<<" "<<(ans+w_1+w_2>dp[v1][v2]+w1+w2)<<endl;
				if(ans+w_1+w_2>dp[v1][v2]+w1+w2){
					ans=dp[v1][v2];
					w_1=w1;
					w_2=w2;
				}
			}
		}
		cout<<w[x]+w[y]+ans+w_1+w_2<<"\n";
	}
	return 0;
}
