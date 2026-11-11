#include<bits/stdc++.h>
#define int long long

using namespace std;
const int inf=1e13+7;
const int N=506;
const int M=5e5+6;
int c,n,m,d,q;
int w[M];
struct mr{
	int id,val;//id:线路编号，val:单程步行时间 
};
vector<mr> e[M];//每个地铁站的线路信息
int dp[N][N];//线路转换floyd 

void init(){
	for(int i=1;i<N;i++){
		for(int j=1;j<N;j++){
			dp[i][j]=inf;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)e[i].size();j++){
			mr u=e[i][j];
			for(int k=0;k<(int)e[i].size();k++){
				mr v=e[i][k];
				if(u.id==v.id)	continue;
				dp[u.id][v.id]=min(dp[u.id][v.id],u.val+v.val);
				dp[v.id][u.id]=dp[u.id][v.id];
			}
		}
	}
}

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}

void solve(int x,int y){
	int temp=inf;
	for(int i=0;i<(int)e[x].size();i++){
		mr u=e[x][i];
		for(int j=0;j<(int)e[y].size();j++){
			mr v=e[y][j];
			temp=min(temp,u.val+dp[u.id][v.id]+v.val);
		}
	}
	cout<<temp+w[x]+w[y]<<endl;
	return;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a,t;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	init();
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
} 
