#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5;
long long a[maxn];
int n, m;
bool check(int k){
	long long sum = 0, mi = LLONG_MAX;
	for(int i = 1;i <= k;i++){
		sum += a[k] - a[i];
	}
	for(int l = 1, r = k;r <= n;l++,r++){
		if(sum < mi){
			mi = sum;
		}
		sum -= a[r] - a[l];
		sum += (k-1) * (a[r+1] - a[r]);
	}
	return mi <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int l = 2, r = n, ans = 1;
	while(l <= r){
		int mid = (l+r) / 2;
		if(check(mid)) l = mid+1, ans = mid;
		else r = mid-1;
	}
	cout << ans;
	return 0;
} 
