#include<iostream>
using namespace std;
int n,m,a[1000001],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1,mx=-100000,p=0;i<=m;i++,mx=-100000){
		for(int j=1;j<=n;j++){
			if(a[j]>mx){
				mx=a[j];
				p=j;
			}
		}
		if(ans) ans=ans&mx;
		else ans=mx;
		a[p]=0;
	}

	cout<<ans;
} 





	/*
	for(int i=2;i<=m;i++){
		for(int j=i;j<=n;j++){
			if(i==j) {
				dp[i][j]=dp[i-1][j-1]&a[j];
				continue;
			}
			for(int x=1;x<=j;x++){
				dp[i][j]=max(dp[i][j],dp[i-1][j-x]&a[j]);
			}
		}
	}*/
	/*
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
