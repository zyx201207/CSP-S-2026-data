#include<bits/stdc++.h>
using namespace std;
int dp[2][200010];
int pre[200010];
int a[200010];
bool checkA(int n){
	for(int i=0;i<=31;i++){
		if(n==(1<<i)-1ll){
			return 1;
		}
	}
	return 0;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cout<<"ok"<<endl;
    int flagA=0,flagB=0;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) flagB=1;
		if(!checkA(a[i])) flagA=1;
	}
	sort(a+1,a+1+n,greater<int>());
	if(flagA==0){
		cout<<a[m]<<endl;
		return 0;
	}
	if(flagB==0){
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i==1) pre[i]=a[i];
		else pre[i]=(pre[i-1]&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,m);j++){
			if(i==j) dp[2][j]=pre[i];
			else dp[2][j]=max(dp[1][j],(dp[1][j-1]&a[i]));
			dp[1][j]=dp[2][j];
			dp[2][j]=0;
		}
	}
	cout<<dp[1][m];
    return 0;
    fclose(stdin);
    fclose(stdout);
}
