#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;

ll n,m,a[N],b[N],ans[N],cost[N],maxans=LLONG_MIN;

int main() {
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		b[i] = a[i];
	}
	int tot = unique(b+1,b+1+n)-b-1;
	for(int i=1; i<=tot; i++) {
		int l = lower_bound(a+1,a+1+n,b[i]) - a,r = upper_bound(a+1,a+1+n,b[i]) - a - 1;
		int cnt = r-l+1+ans[i-1];
		ll sum = cost[i-1]+ans[i-1]*(b[i]-b[i-1]);
		while(sum > m){
			sum -= b[i]-a[r-cnt+1];
			cnt--;
		}
		ans[i] = cnt,cost[i] = sum;
	}
	for(int i=1;i<=tot;i++){
		maxans = max(ans[i],maxans);
	}
	cout << maxans;
	return 0;
}

