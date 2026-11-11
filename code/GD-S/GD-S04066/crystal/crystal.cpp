#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 5e5+10;
ll n,m;
ll a[ms];
ll min_ = 1e9,max_ = -1e9;
int ans = -1;

bool flag = 1;

int check(ll num) {
	int l = 1,r = n,mid;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if(a[mid] <= num) l = mid;
		else r = mid - 1;
	}
	
	int sum = 0,cnt = 0;
	for(int i = l;i >= 1 && sum <= m;i--) {
		sum += num-a[i];
		if(sum <= m) cnt++;
	}
	return cnt;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		min_ = min(min_,a[i]); max_ = max(max_,a[i]);
		if(i != 1 && i != 2) {
			if(a[i]-a[i-1] != a[i-1]-a[i-2]) flag = 0;
		}
	}
	sort(a+1,a+n+1);
	
	if(max_ > 1e5 || min_ < -1e5) {
		if(flag) {
			int k = a[2] - a[1],i = 1;
			if(k == 1) {
				for(;i <= m;i++) {
					if(i*(i-1)/2 > m) break;
				}
				cout << i-1;				
			}
			else {
				if(m == 1) {
					cout << 1;
					return 0;
				}
				for(;i <= m;i+=k) {
					if((i+1)*(i-1)/k/2 > m) break;
				}
				cout << (i-1)/k;
			}
			return 0;

		}		
	}

	
	ll l = min_,r = max_;
	
	for(ll i = l;i <= r;i++) {
		ans = max(ans,check(i));
	}
	
	cout << ans;
	return 0;
}
