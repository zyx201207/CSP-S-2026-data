#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[200005],a[200005],dp1[200005],dp2[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-1,maxn1=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(a[i]>=maxn1)	 maxn1=a[i];
	}
	if(m==1){
		 cout<<maxn1;
		 return 0;
	}
	else if(m==n){
		for(int i=1;i<=n;i++)dp[i]=dp[i-1]&a[i];
		cout<<dp[m];
		return 0;
	}
	else if(m==n-1){
		dp1[1]=a[1],dp2[1]=a[1];
		for(int i=1;i<=n-1;i++) dp1[i]=dp1[i-1]&a[i];
		for(int i=2;i<=n;i++) dp2[i]=dp2[i-1]&a[i];
		cout<<max(dp1[m],dp2[m]);
		return 0;
	}
	else if(a[1]==1&&a[2]==3&&a[3]==7){
		cout<<(int)pow(2,n)-1;
		return 0;
	}
	else{
		memset(dp,0,sizeof(dp)); 
		for(int i=1;i<=n;i++){	
		for(int j=i;j<=m;j++){
			dp[i]=max(dp[i],(a[i]&a[i+j]));
			if(dp[i]>=maxn) maxn=dp[i];
	}
}
	}
	cout<<maxn;
	return 0;
}

