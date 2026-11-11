//贵阳市第一中学  黄弈嘉  GZ-S00217
#include <bits/stdc++.h>
using namespace std;
/*
我们构造两个数组q,k,其中q 为int 数组 ， q[i][j] 表示的是i号线能到达的站台。 k数组为int 数组， k[i][j][0] 表示在第i站第q号线，从地铁口走到站厅的时间 ， q = k[i][j][1]。
更新一下：我们用k[an_i][0][0] 表示an_i 号站台总共有几条线路经过 , 用q[i][0] 表示i条线路经过几站。
我尝试用dp[a][b] 表示第a号站厅到第b号站厅的最优时间。         ——注意！！！！：这里是站厅，不是站台。
先初始化：
for（int i = 1;i <= m;i++) dp[i][i] = 0;
 接下来我们要做的是：
第一步 ： 去遍历每一个i ，更新他可以直接抵达的位置： q[ k[i][j][1] ][t] 表示站号。 k[i][j][1] 表示几号线
for(int j = 1;j <= k[i][0][0];j++){
    for（int t = 1；t <= q[ k[i][j][1] ][0] ; t++){
        if(i == q[ k[i][j][1] ][t] ) continue;
        if( dp[i][  q[ k[i][j][1] ][t] ] == 0)  dp[i][q[ k[i][j][1] ][t] ] = k[i][ y[i][k[i][j][1]] ][0] + k[ q[ k[i][j][1] ][t] ][ y[ q[ k[i][j][1]  ][ t ]  ][ k[i][j][1] ] ][0];
        else dp[i][q[ k[i][j][1] ][t] ] = min( k[i][ y[i][k[i][j][1]] ][0] + k[ q[ k[i][j][1] ][t] ][ y[ q[ k[i][j][1]  ][ t ]  ][ k[i][j][1] ] ][0] , dp[i][q[ k[i][j][1] ][t] ]);
    }
}

第二步，构建不直接相连的两站a,b：
for（int i =1;i <= m;i++){
    for(int j = 1;j <= m;j++){
        if(dp[i][j] == 0) continue;
        for(int k = 1;k <= m;k++){
            if(dp[j][k] == 0) contiue;
            if(dp[i][k] == 0) dp[i][k] = dp[i][j] + dp[i][k];
            else  dp[i][k] = min(dp[i][k],dp[i][j] + dp[i][k]);
        }
    }
}

*/

const int N = 1005 , M = 505; // M 为线路数，N为站数
int c,n,m,d,p;
int w[N],q[M][N],k[N][M][3],dp[M][M],y[N][M];

 signed main(){
	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
 	cin>>c>>n>>m>>d>>p;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1;i <= n;i++){
		cin>>q[i][0];
		for(int j = 1;j <= q[i][0];j++){
			int a1,t1; cin>>a1>>t1;
			q[i][j] = a1;
			k[a1][0][0]++;
			k[a1][ k[a1][0][0] ][1] = i;
			k[a1][ k[a1][0][0] ][0] = t1;
			y[a1][i] = k[a1][0][0];
		}
	}
//	cout<<"\n\n\n";
	for(int i = 1;i <= m;i++) dp[i][i] = 0;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= k[i][0][0];j++){
	    		for(int t = 1;t <= q[ k[i][j][1] ][0] ; t++){
	        			if(i == q[ k[i][j][1] ][t] ) continue;
	        			if( dp[i][  q[ k[i][j][1] ][t] ] == 0)  dp[i][q[ k[i][j][1] ][t] ] = k[i][ y[i][k[i][j][1]] ][0] + k[ q[ k[i][j][1] ][t] ][ y[ q[ k[i][j][1]  ][ t ]  ][ k[i][j][1] ] ][0];
	        			else dp[i][q[ k[i][j][1] ][t] ] = min(k[i][ y[i][k[i][j][1]] ][0] + k[ q[ k[i][j][1] ][t] ][ y[ q[ k[i][j][1]  ][ t ]  ][ k[i][j][1] ] ][0] , dp[i][q[ k[i][j][1] ][t] ]);
//						cout<<"dp["<<i<<"]["<<q[ k[i][j][1] ][t]<<"] = "<<dp[i][q[ k[i][j][1] ][t] ]<<"  "<<k[i][ y[i][k[i][j][1]] ][0]<<"    k["<<q[ k[i][j][1] ][t]<<"]["<<q[ k[i][j][1]  ][ t ]<<" ][0]= "<<k[ q[ k[i][j][1] ][t] ][ y[ q[ k[i][j][1]  ][ t ]  ][ k[i][j][1] ] ][0]<<"         ";				
						}
//				cout<<"\n";
		}
	}
//	cout<<"\n\n\n";
	for(int i =1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			if(i == j) continue;
			if(dp[i][j] == 0) continue;
			for(int k = 1;k <= m;k++){
				if(j == k || i == k) continue;
   				if(dp[j][k] == 0) continue;
    			if(dp[i][k] == 0) dp[i][k] = dp[i][j] + dp[j][k];
   				else  dp[i][k] = min(dp[i][k],dp[i][j] + dp[j][k]);
//   				cout<<"dp["<<i<<"]["<<k<<"] = "<<dp[i][k]<<"    "; 
			}
//			cout<<"\n";
	 	}
	}
//	cout<<dp[1][2]<<"    "<<dp[2][3]<<"   "<<dp[1][3]<<"\n";
	for(int i = 1;i <= p;i++){
		int x,y; cin>>x>>y;
		int ans = w[x]+w[y];
		ans += dp[x][y];
//		cout<<"W["<<x<<"] = "<<w[x] << "     W["<<y<<"] = "<<w[y]<<"    dp["<<x<<"]["<<y<<"] = "<<dp[x][y]<<"    ";
		cout<<ans<<"\n";
	}
 	return 0;
 }



