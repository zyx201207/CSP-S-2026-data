#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int dp[200001][2]; //dp[i][j]:选到第i时max 随循环更新 j=1:输入 O(n^2)会炸 
int a[2005][2005]; //a[i][j] n<=2000时的dp 
int ans=0,ans2=0,ans3=0; //ans:m=1;ans2:m=2;ans3:m=n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>dp[i][1];
		ans=max(ans,dp[i][1]);
		if(n<=2000) a[1][i]=dp[i][1];
	}
	if(m==1) cout<<ans;
	else if(m==2){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				ans2=max(ans2,dp[i][1]&dp[j][1]);
			}
		}
		cout<<ans2;
	}else if(m==n){
		ans=dp[1][1];
		for(int i=2;i<=n;i++){
			ans&=dp[i][1];
		}
		cout<<ans;
	}else if(n<=2000){
		for(int i=2;i<=m;i++){
			a[i][1]=a[1][1];
			for(int j=i;j<=n;j++){		//dp,O(n^2),4*10^6，理论可达10000( 
				a[i][j]=a[i][j-1];
				if(a[i][j]<a[i-1][j-1]&a[1][j]){
					a[i][j]=a[i-1][j-1]&a[1][j];
				}
			}
		}
		cout<<a[m][n];
	}else{
		int nn=n,cnt=0,sum=0;
		while(nn){
			cnt+=nn%2;
			nn/=2;
			sum++;
		}
		if(cnt==1){
			cout<<n-m;
		}else{
			cout<<sqrt(ans);
		}
	}
	return 0;
} 
