#include<bits/stdc++.h> 
#define int long long 
using namespace std;
const int inf=1e15;
int c,t,n,d,x[2000005],dp[5005][5005],mi[5005][5005],ans;
void init(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=0;
			mi[i][j]=inf;
		}
	}
	return ;
}
void solve(){
	cin>>n>>d;
	init();
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=i-1;j>=1;j--){
			if(x[i]-x[j]<=d){
			    dp[j][i]=1;
			    mi[j][i]=1;
		    }
			//cout<<j<<" "<<i<<" "<<dp[j][i]<<" "<<mi[j][i]<<"\n";
		}
	}
	for(int len=3;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			//cout<<i<<" "<<j<<" "<<mi[i][j]<<"\n";
			for(int k=j-1;k>i&&x[j]-x[k]<=d;k--){
			    if(mi[i][k]+mi[k][j]<mi[i][j]){
				    dp[i][j]=dp[i][k]*dp[k][j];
				    mi[i][j]=mi[i][k]+mi[k][j];
				    //cout<<"1 "<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<" "<<mi[i][j]<<"\n";
			    }
			    else if(mi[i][k]+mi[k][j]==mi[i][j]){
				    dp[i][j]+=dp[i][k]*dp[k][j];
				    //cout<<"2 "<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<" "<<mi[i][j]<<"\n";
			    }
		    }
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[i][j]==2) ans++;
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
