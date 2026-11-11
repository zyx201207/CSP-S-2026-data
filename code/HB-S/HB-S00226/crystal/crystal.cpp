#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	vector<long long> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	long long sum = 1;
	if(n > 5000){
		long long s = a[2] - a[1];
		for(int i = 1; i <= n; i ++){
			if(m - s * sum >= 0){
			    m -= s * sum;
			    sum ++;
		    } else {
			    continue;
		    }
		}
	} else {
	sort(a.begin(), a.end());
	for(int i = 1; i < n; i ++){
		if(a[i] == a[i + 1]){
			sum ++;
		} else {
			int t = a[i + 1] - a[i];
		    if(m - t * sum >= 0){
			    m -= t * sum;
			    sum ++;
		    } else {
			    continue;
		    }
		}
	}
    }
	cout << sum;
    return 0;
}
