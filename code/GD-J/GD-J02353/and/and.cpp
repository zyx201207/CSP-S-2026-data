#include<iostream>
#include<algorithm>
using namespace std;
int a[200100];
int dp[200100];
int w[200100];

int n,m;
//数量，可选次数 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n==m){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i-1];
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			w[i]=1;
		}
		for(int i=1;i<=n;i++) dp[i]=a[i];
		for(int i=1;i<=n;i++){
			for(int j=m;j>=w[i];j--){
				dp[i]=max(dp[i],dp[j-w[i]]&a[i]);
			}
		}
		cout<<dp[n];
	}
} 
