#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int dp[5005][5005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][0]=(1<<25)-1;
    }
    dp[1][1]=a[1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i==1&&j==1) continue;
            dp[i][j]=max((dp[i-1][j-1]&a[i]),dp[i-1][j]);
            //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][m];
	return 0;
}
