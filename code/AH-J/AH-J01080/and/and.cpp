#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long n,m,a[214514],dp[214514],ans;
bool cmp(long long x,long long y) {
	return x>y;
}
bool check(long long x) {
	for(int i=1; i<=x; i++) {
		for(int j=1; j<=x; j++) {
			if(i!=j&&a[i]==a[j]) return 1;
		}
	}
	return 0;
}
long long check1(long long x) {
	for(int i=1; i<=x; i++) {
		for(int j=1; j<=x; j++) {
			if(i!=j&&a[i]==a[j]) return a[i];
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	//for(int i=1; i<=n; i++) cout<<a[i]<<" ";
	ans=a[1];
	if(m==1) {
		cout<<a[1];
		return 0;
	}
	else if(n==m) {
		for(int i=1; i<=m; i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	else if(m==n-1) {
		if(check(n)) {
			cout<<check1(n);
			return 0;
		}
		for(int i=1; i<=m; i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	else if(m==2) {
		if(check(n)) cout<<check1(n);
		else cout<<(a[1]&a[2]);
		return 0;
	}
	for(int i=1; i<=m; i++) ans=(ans&a[i]);
	cout<<ans;
	return 0;
} 
