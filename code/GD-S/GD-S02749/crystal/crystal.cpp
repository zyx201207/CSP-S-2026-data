#include<iostream>
#include<algorithm>
using namespace std;

const long long maxn = 5e5+5;
long long n,m;
long long a[maxn];
long long sum[maxn];

bool check(long long x){
	for (long long l = 1;l + x - 1 <= n;l++){
		long long r = l + x - 1;
		long long s = sum[r-1] - sum[l-1];
		long long maxx = a[r];
		long long cost = maxx * (x - 1) - s;
		if (cost <= m) return true;
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (long long i = 1;i <= n;i++){
		sum[i] = sum[i-1] + a[i];
	}
	long long l = 1,r = n,ans = -1;
	while (l <= r){
		long long mid = (l + r) / 2;
		if (check(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans;
}
