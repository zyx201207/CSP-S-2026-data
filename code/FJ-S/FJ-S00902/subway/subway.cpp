#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int M=5e5+5,N=5e2+5;
ll dp[N][N];
int w[M];
int dis[M][21];
vector<int>v[M];
//两条线路的最小长度 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	//这个线路其实有0个作用
	//这个d给的也很何意位
	//那肯定是要我们直接枚举了，毕竟就20个
	//首尾的这个固定了
	//反正肯定要预处理 
	//刚刚试了一下，好像可以转化成线段交集问题
	//flody神力 
	memset(dp,0x3f,sizeof dp);
	
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=0;//自己到自己=0 
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			v[a].push_back(i);//被经过的线路
			dis[a][(int)v[a].size()-1]=t; 
		}
	} 
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				if(v[i][j]==v[i][k])continue;
				//cout<<dis[i][v[i][j]]+dis[i][v[i][k]]<<"\n\n";
				dp[v[i][j]][v[i][k]]=dp[v[i][k]][v[i][j]]=min(dp[v[i][j]][v[i][k]],(ll)dis[i][j]+dis[i][k]);
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
		ll ans=LLONG_MAX;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,dp[v[x][i]][v[y][j]]+dis[x][i]+dis[y][j]);
			}
		}
		//cout<<ans<<"\n";
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
