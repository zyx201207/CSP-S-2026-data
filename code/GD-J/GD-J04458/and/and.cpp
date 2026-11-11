#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005+10;
int dp[N];
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=a[i];
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i>=j;i--){
			dp[i]=max(dp[i],dp[i-1]&a[i]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}

