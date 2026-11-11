#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int dp[3005][3005]={0},n,m,a[1000005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int d=0;
		for(int i=1;i<=n;i++){
			d=max(d,a[i]);
		}
		cout<<d;
		return 0;
	}
	if(m==2){
		
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][2]=max(dp[i][2],a[i]&a[j]);
		}
		
	}
	cout<<dp[n][2];
	return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			a[1]&=a[i];
		}
		cout<<a[1];
		return 0;
	}
	return 0;
}
