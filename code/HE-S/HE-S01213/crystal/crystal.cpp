#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long ans; 
long long a[500005];

bool cmp(long long x, long long y){
	return x <= y;
}

long long check(long long mid){
	long long cnt = 1; 
	long long e = m;
	// 向左操作
	for(long long i=mid-1;i>=1;i--){
		if(e >= abs(a[mid] - a[i]) && e >= 0){
			cnt++;
			e -= abs(a[mid] - a[i]);
		}else break;
	} 
	return cnt;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+1+n,cmp);
	
	long long l = 1, r = n;
	
	while(l <= r){
		long long mid = (l+r)/2; // 检查区间中位数 
		long long res = check(mid); 
		//cout << l << ' ' << r << ' ' << mid << ' ' << res << endl;
		if(res > ans){
			ans = res;
			l = mid+1;
		} else {
			r = mid-1;
		} 
	}
	
	cout << ans; 
	
	return 0;
}
