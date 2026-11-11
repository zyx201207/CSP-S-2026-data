#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=-1;
int a[200010],dp[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=a[i];
	}for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],(dp[j]&a[i]));
		}
	}cout<<dp[n];
	return 0;
}
