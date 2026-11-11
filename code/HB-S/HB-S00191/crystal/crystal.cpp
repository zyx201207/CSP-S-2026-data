#include<bits/stdc++.h>
using namespace std;

long long a[500010];
long long m, n, num;

int half(long long l, long long r){
	long long mid = (l + r) / 2;
	int o;
	num = 0;
	for(long long i = 1; i <= m; i++){
		if(mid > a[i]){
			num += mid;
			num -= a[i];
		}else{
			if(a[i] != a[i + 1]){
				o = i;
				break;
			}
		}
	}
	if(num > m){
		return half(l, mid);
	}else if(num < m){
		return half(mid, r);
	}
	else{
		return o;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cout << half(a[1], a[n]);
	
	return 0;
}
