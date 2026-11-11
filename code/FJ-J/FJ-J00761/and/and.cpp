#include<bits/stdc++.h>
#include<string>
using namespace std;
long long dp[200005][31],l,f[200005],ans[31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		int l=30;
		while(x){
			dp[i][l]=x%2;
			x/=2;
			l--;
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<31;j++){
//			cout<<dp[i][j];
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for(int i=1;i<31;i++){
		l=0;
		for(int j=0;j<n;j++){
			if(f[j]==1)continue;
			if(dp[j][i]==1)l++;
		}
		if(l>=m){
			ans[i]=1;
			for(int j=0;j<n;j++){
				if(f[j])continue;
				if(dp[j][i]==0)f[j]=1;
			}
		}
	}
//	cout<<endl;
//	for(int j=1;j<31;j++){
//		cout<<ans[j];
//	}
	long long ans1=0,base=1;
	for(int j=30;j>0;j--){
		ans1+=base*ans[j];
		base*=2;
	}
	cout<<ans1;
	return 0;
}
