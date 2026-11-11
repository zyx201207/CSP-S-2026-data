#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int c,n,m,d,q,w[N],dp[N][N];
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];//end's time add;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[k+5],t[k+5];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
			   int both_sum=t[l]+t[j];
			   int xba=a[j],xbb=a[l];
			   dp[xba][xbb]=both_sum;
			   dp[xbb][xba]=both_sum;
		    }
		}
		
	}
	
	for(int k=1;k<=m;k++){
	    for(int i=1;i<=m;i++){
	    	for(int j=1;j<=m;j++){
	    		if(dp[i][k]==0||dp[j][k]==0){
	    			continue;
				}
				if(dp[i][j]==0) dp[i][j]=dp[i][k]+dp[k][j];
				else dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	//write answer
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
	
	return 0;
}


