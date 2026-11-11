#include<bits/stdc++.h>
using namespace std;

const int N = 500050;

long long a[N], b[N], ans[N];
long long n, m;

bool check(int mid, int start){
	long long ans = 0;
	for(int i = start; i < mid; i++){
		ans = ans + a[mid] - a[i];
	}
	if(ans <= m){
		m -= ans;
		return true;
	}else{
		return false;
	}
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	long long l = 1, r = n;
	
	while(l + 1 < r){
		long long mid = (l + r) / 2;
		if(check(mid, l)){
			l = mid;
		}else{
			r = mid;
		}
		if(m == 0){
			break;
		}
	}
	
	long long ans = l;
	for(int i = l + 1; i <= n; i++){
		if(a[i] == a[l]){
			ans++;
		}else{
			break;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
