#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

struct node{
	ll id,val;
	//值，下标； 
};
int c,n,m,d,q;
//测试点编号，地铁线路，地铁几个站，每个站几个线路，几个出行计划
ll dp[510][510];
ll a[510];//出站时间 
ll t[510];//站厅出去的时间 
void floyd(){
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				dp[i][k]=min(dp[i][j]+dp[j][k],dp[i][k]);
			}
		}
	}
	return;
} 
void chu(){
	for(int i=1;i<=505;i++){
		for(int j=1;j<=505;j++){
			if(i==j) dp[i][j]=0;
			else dp[i][j]=1e9;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	chu();
	for(int i=1;i<=n;i++){
		cin>>t[i];
	} 
	
	while(m--){
		node xian[510];
		int shu;//这个线路几个站
		cin>>shu;
		for(int i=1;i<=shu;i++){
			cin>>xian[i].id>>xian[i].val;
		}
		for(int i=1;i<=shu;i++){
			for(int j=i+1;j<=shu;j++){
				int x=xian[i].id;
				int y=xian[j].id;
				dp[x][y]=min(dp[x][y],xian[i].val+xian[j].val);
				dp[y][x]=min(dp[y][x],xian[i].val+xian[j].val);
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+t[x]+t[y]<<"\n";
	}
} 
