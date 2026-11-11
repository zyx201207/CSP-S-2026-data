#include<bits/stdc++.h>
using namespace std;
long long n, m, sum, ans, mm, k;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	mm = m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sum /= n;
	sort(a+1,a+1+n);
	long long l = 1, r = n;
	while(l < r){
		int mid = (l+r+1) / 2;
		if(a[mid] > sum){
			r = mid - 1;
		}else{
			l = mid;
		}
	}
	k = (l+r) / 2;
	for(int j  = k; j >= 1; j--){
		if(m >= sum - a[j]){
			m -= sum - a[j];
			a[j] = sum;
		}else{
			break;
		}
	}
	a[0] = INT_MIN;
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i-1]){
			long long cnt = 1;
			int j;
			for(j = i; j <= n; j++){
				if(a[j] == a[j-1]) cnt++;
				else break;
			}
			i = j;
			ans = max(cnt, ans);
		}
	}
	if(m > 0){
		if(m < a[k]){
			for(int i = k; i >= k-m+1; i--){
				a[i]++;
			}
		}else{
			long long x = m / k;
			for(int i = k; i >= 1; i--){
				a[i] += x;
				m -= x;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i-1]){
			long long cnt = 1;
			int j;
			for(j = i; j <= n; j++){
				if(a[j] == a[j-1]) cnt++;
				else break;
			}
			i = j;
			ans = max(cnt, ans);
		}
	}
	if(m > 0){
		if(m < a[k]){
			for(int i = k; i >= k-m+1; i--){
				a[i]++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i-1]){
			long long cnt = 1;
			int j;
			for(j = i; j <= n; j++){
				if(a[j] == a[j-1]) cnt++;
				else break;
			}
			i = j;
			ans = max(cnt, ans);
		}
	}
	cout << ans;
	return 0;
} 
