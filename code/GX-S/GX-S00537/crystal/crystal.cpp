#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],dp[10005][50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
		int sum=0;
        for(int j=1;j<=i;j++){
            dp[i][j]=a[i]-a[j];
            sum+=dp[i][j];
        }
        dp[i][0]=sum;	
	}
    for(int i=1;i<=n;i++){
		if(dp[i][0]==m && dp[i+1][0]!=m){
			cout<<i;
			break;
		}
		else if(dp[i][0]<m && dp[i+1][0]>m){
			cout<<i;
			break;
		}
			
	}
    return 0;
}
