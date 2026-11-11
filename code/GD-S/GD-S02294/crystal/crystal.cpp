#include <bits/stdc++.h>

using namespace std;

long long n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> n >> m;
	bool flag1 = 1,flag2 = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i)
			flag1 = 0;
		if(i >= 3 and (a[i] - a[i - 1] != a[i - 1] - a[i - 2]))
			flag2 = 0;
	}
	long long cur = 0,ans = -1,cnt = 0;
	if(flag1){
		int i = 1;
		long long l = 1,r = n + 5;
		while(l <= r){
			long long mid = l + (r - l + 1) / 2;
			if(mid * (mid + 1) <= 2 * m)
				ans = mid,l = mid + 1;
			else
				r = mid - 1;
		}
		cout << ++ans;
		return 0;
	}
	if(flag2){
		long long l = 1,r = n + 5;
		while(l <= r){
			long long mid = l + (r - l + 1) / 2;
			if((a[2] - a[1]) * mid * (mid + 1) <= 2 * m)
				ans = mid,l = mid + 1;
			else
				r = mid - 1;
		}
		cout << ans;
		return 0;
	}
	for(long long i = 1;i <= n;i++){
		cur = 0,cnt = 0;
		long long j = i;
		while(j >= 1 and cur <= m){
			cnt++;j--;
			//cout << a[i] <<" " << a[j] <<" " << cnt <<'\n';
			cur += (a[i] - a[j]);
			
		}
		ans = max(ans,cnt);
	}
	
	cout << ans;
	
	return 0;
} 
