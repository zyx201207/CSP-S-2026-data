#include<bits/stdc++.h>
using namespace std;
int n,m;
long long arr[200005],dp[200005];
bool cmp(long long x,long long y){return x>y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=2;j--){
			dp[j]=max(dp[j],dp[j-1]&arr[i]);
		}
		dp[1]=arr[i];
	}
	cout<<dp[m];
	return 0;
}
