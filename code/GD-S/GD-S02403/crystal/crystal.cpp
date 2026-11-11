#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N = 5e5+5;
long long a[N];
long long dp[N];
int ans = 1;
bool check(int x,int y){
	if(dp[y]+(a[y]-a[x])<=m) return true;
	else return false;
}
int bs(int now){
	int l = 1,r = n;
	while(l<r){
		int mid = (l+r+1)/2;
		if(check(now,mid)){
			l = mid;
		}
		else{
			r = mid-1;
		}
	}
	return l;
}
void solve1(){
	for(int i = 1;i<=n;i++){
		if(i!=1&&a[i]==a[i-1]) continue;
		dp[i] = 0;
		for(int j = i+1;j<=n;j++){
			long long k = a[j]-a[j-1];
			dp[j] = dp[j-1]+k*(j-i);
			if(dp[j]>m){
				ans = max(ans,j-i);
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool ok = 1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i-1]-a[i-2]!=a[i]-a[i-1]) ok = 0;
	}
	sort(a+1,a+n+1);
	dp[1] = 0;
	for(int i = 2;i<=n;i++){
		long long k = a[i]-a[i-1];
		dp[i] = dp[i-1]+k*(i-1);
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(ok){
		for(int i = 1;i<=n;i++){
			if(dp[i]>m){
				ans = i-1;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=5000){
		solve1();
		return 0;
	}
	for(int i = 1;i<=n;i++){
		if(i!=1&&a[i]==a[i-1]) continue;
		int x = bs(i);
		ans = max(ans,x-i+1);
	}
	cout<<ans;
	return 0;
}

