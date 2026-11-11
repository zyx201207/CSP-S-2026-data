#include<bits/stdc++.h>
using namespace std;
long long dp[200010][2],a[100010],n,m,maxi=0,k1,k2,b1,b2;
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==n){
		maxi=a[1];
		for(int i=2;i<=n;i++){
			maxi&=a[i];
		}
		cout<<maxi;
		return 0;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			maxi=max(maxi,a[i]);
		}
		cout<<maxi;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxi=max(maxi,a[i]&a[j]);
			}
		}
		cout<<maxi;
		return 0;
	}
    else{
		for(int i=1;i<=m;i++){
	       k1=dp[i-1][0];
	       k2=dp[i-1][1];
	       dp[i][0]=max(dp[i-1][0],max(k1,k2));
	       b1=dp[i-1][0]^a[i];
	       b2=dp[i-1][1]^a[i];
	       dp[i][1]=max(dp[i-1][1],max(b1,b2));
	       maxi=max(maxi,max(dp[i][0],dp[i][1]));	
	    }
	}
	cout<<maxi/4;
    return 0;
}
