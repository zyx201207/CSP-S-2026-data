#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans = 1;
bool check(int x){
	for(int i = 1;i<=n-x+1;i++){
		long long sum = a[i+x-1]*x;
		long long cnt = s[i+x-1]-s[i-1];
		if(sum-cnt<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in",r,stdin);
	freopen("crystal.out",w,stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		s[i] = s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int l = 1,r = n;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)){
			ans =mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout << ans;
	return 0;
}
