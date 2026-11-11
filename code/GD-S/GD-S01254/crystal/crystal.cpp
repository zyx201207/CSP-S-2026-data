#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long n, m, ans = 0;
long long lb(long long x){
	long long l = 1, r = n;
	while(l <= r){
		long long mid = (l+r)>>1;
		if(a[mid] < x){
			l = mid +1;
		}else if(a[mid] == x){
			return mid;
		}else{
			r = mid-1;
		}
	}
	return l;
}
void ch(long long x){
	long long o = m, cnt = 0;
	long long w = lb(x);
	while(1){
		if(a[w]==a[w+1]){
			w++;
		}else{
		    break;
		}
	}
	while(1){
		if(a[w] > x){
			w--;
		}else{
			break;
		}
	}
	for(long long i = w; i >= 1; i--){
		if(o >= (x-a[i])){
			o -= (x-a[i]);
			cnt++;
		}else{
			break;
		}
	}
	ans = max(ans, cnt);
	return;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(long long i = a[1]; i <= a[n]; i++){
		ch(i);
	}
	cout << ans;
	return 0;
}
