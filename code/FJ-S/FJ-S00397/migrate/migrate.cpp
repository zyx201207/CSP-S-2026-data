#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 2e6 + 5 ;
int c,t;
int n,m;
int a[N];
int dp[N];
int b[N];
int ans=0;
void AwA(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		dp[i-1]=0;b[i-1]=0;
		dp[i]=1;b[i]=1;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>m)continue;
			dp[j]=1;
			for(int k=j-2;a[j]-a[k]<=m&&k>0;k--){
				if(b[j-1]==b[k]){
					dp[j]++;b[j]=b[j-1]+1;
				}else if(b[j-1]>b[k]){
					dp[j]=1,b[j]=b[k] + 1;
				}
				//cout<<i-1<<" "<<j<<" "<<dp[j]<<" "<<b[j]<<" "<<k<<endl;
			}
			if(dp[j]==2){
				ans++;
				//cout<<i-1<<" "<<j<<endl;
			}
			if(dp[j]>2)continue;
		}
	}
	cout<<ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		AwA();
		t--;
	}
	return 0;
}

