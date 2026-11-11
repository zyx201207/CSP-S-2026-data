//自己都看不懂。。。
//csp RP++ !!!
#include<bits/stdc++.h>
using namespace std;
long long m,c,n,d,q,w[1005],x,y,k[1005],a,t,dtz[1005][505],dp[505][505];//dtz:各个地铁站经过的线路的时间   dp:a和b两条线路之间的最短时间
bool dtz1[505][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//测试点编号 地铁线路数 地铁站数 每个地铁站最多被几条线路经过 出行计划数
	memset(dp,0x3f3f3f,sizeof dp);
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];//每个地铁站从地铁口走到站厅的时间 
	}
	
	//建图 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;//第i条线路经过的第j个地铁站  该地铁站从站厅走到第i条线路的站台所需要的时间 
			dtz[i][a]=t;
			dtz1[a][t]=1;
		}
	}
	for(int l=1;l<=n;l++){
		for(int o=1;o<=n;o++){
			for(int p=1;p<=n;p++){
				for(int q=1;q<=n;q++){
					if(dtz1[l][p]==dtz1[o][q]){
						dp[o][l]=min(dp[o][l],dtz[l][p]+dtz[l][q]);
					}
				}
			}
		}
	}
	
	//答案 
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		long long minout=1e18;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(dtz1[j][x]&&dtz1[l][y]){
					minout=min(minout,dp[j][l]+w[j]+w[l]+dtz[j][x]+dtz[l][y]);
				}
			}
		}
		cout<<minout<<endl;
	}
	return 0;
}
