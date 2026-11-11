#include <bits/stdc++.h>
using namespace std;
long long a[500005] = {};
long long s[500005] = {};
long long n ,m;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	long long l = 1,r = n;
	long long ans = -1;
	sort(a+1,a+n+1);
	for (long long i = 1; i <= n; i++) s[i] = s[i-1]+a[i]; 
	while(l <= r){
		long long mid = l+(r-l)/2;
		long long sum = a[mid]*mid - s[mid];
		if(sum <= m){
			ans = max(ans,mid);
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout << ans;
	return 0;
} 
