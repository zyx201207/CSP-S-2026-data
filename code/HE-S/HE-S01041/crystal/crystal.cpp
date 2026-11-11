#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[n];
	for(long long i = 0;i < n;i++) cin >> a[i];
	sort(a,a + n);
	if (a[0] == a[n - 1]){
		cout << n;
		return 0;
	}
	long long i = (n - 1) / 2,cnt = 1,l = i - 1,r = i + 1;
	while (m){
		if((l == -1 && r == n) || (m < a[r] - a[i] && m < a[i] - a[l])) break;
		if(a[i] - a[l] < a[r] - a[i] && m >= a[i] - a[l] && l > 0){
			m -= a[i] - a[l];
			l--;
			cnt++;
		}else if(a[i] - a[l] > a[r] - a[i] && m >= a[r] - a[i] && r < n - 1) {
			m -= a[r] - a[i];
			r++;
			cnt++;
		}else if(a[l] == a[r]){
			l--;
			r++;
			cnt += 2;
		}else if(n - r - 1 >= l + 1){
			m -= a[r] - a[i];
			r++;
			cnt++;
		}else {
			m -= a[i] - a[l];
			l--;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
