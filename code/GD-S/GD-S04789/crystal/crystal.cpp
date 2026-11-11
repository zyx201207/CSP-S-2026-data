#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5e5+5;

int n, m, a[maxn], ans = 0;
ll num[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	
	for(int i = 1; i <= n; i++) {
		num[i] = num[i-1] + a[i];
	}
	
	int l = 1, r = n, lst;
	while(l < r){
		int mid = (l + r) >> 1;
		bool flag = 0;
		if(mid == lst) break;
//		cout << l << " " << r << " "<< mid << ":\n";
		for(int i = mid; i <= n; i++){
			ll sum = mid * a[i];
//			cout << i <<" "<< num[i] - num[i-mid] << " " << sum << "\n";
			if(sum - (num[i] - num[i-mid]) <= m){
				flag = 1;
				break;
			}
		}
//		cout << "\n";
		if(flag) l = mid;
		else r = mid;
		lst = mid;
	}
	
	cout << lst;
	return 0;
}

