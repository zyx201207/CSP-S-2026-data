#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
long long a[N], b[N], d[N], cnt, ans, sum, l, sum2;
char c[N], w[N], e[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		cnt += a[i]; 
	}
	cnt = (cnt % 2 ? (cnt-1)/2 : cnt/2);
	for(int i = 1; i <= n; i++){
		if(ans+a[i] > cnt){
			b[++sum] = cnt-ans;
			w[sum] = c[i];
			break;
		} else {
			b[++sum] = a[i]; 
			w[sum] = c[i];
			if(ans + a[i] < cnt){
				ans += a[i];
			} else {
				break;
			}
		} 
	}
	ans = 0;
	for(int i = n; i >= 1; i--){
		if(ans+a[i] > cnt){
			d[++l] = cnt-ans;
			e[l] = c[i];
			break;
		} else {
			d[++l] = a[i]; 
			e[l] = c[i];
			if(ans + a[i] < cnt){
				ans += a[i];
			} else {
				break;
			}
		}
	}
	ans = 0, cnt = 0;
	for(int i = 0, j = 0; i <= sum&&j <= l;){
		if(!ans){
			i++;
			ans = b[i];
		}
		if(!cnt){
			j++;
			cnt = d[j];
		}
		if(w[i] != e[j]){
			if(ans > cnt){
				sum2 += cnt;
				ans -= cnt;
				cnt = 0;
			} else {
				sum2 += ans;
				cnt -= ans;
				ans = 0;
			}
		} else {
			if(ans > cnt){
				ans -= cnt;
				cnt = 0;
			} else {
				cnt -= ans;
				ans = 0;
			}
		}
	}
	cout << sum2;
	return 0;
}
