#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 5e5 + 10;
long long a[maxn];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	//special A & special B
	bool isB = true;
	int d = a[2] - a[1];
	for (int i = 1; i <= n; i++){
		if (a[i] - a[i - 1] != d){
			isB = false;
			break;
		}
	}
	if (isB){
		int i = 0;
		long long sum = 0;
		while (sum <= m){
			i++;
			sum += a[i];
		}
		cout << i;
		return 0;
	}
	
	//O(n^2)
	long long ans = 1;
	for (long long i = 1; i <= n; i++){
		long long cur = 0;
		for (long long j = i - 1; j >= 0; j--){
			cur += a[i] - a[j];
			if (cur > m || j == 0){
				ans = max(ans, i - j);
				break;
			}
		}
	}
	cout << ans;
	
	return 0;
}

//14:42 I can finally read t1 qwq
//why did the test place let us in 5 minutes before the test began???
//qwq
//14:55 O(n^2) 45pts, AB 30pts: come up with 75pts methods
//15:34 special A&B 30pts got
//15:53 75pts got
//the ans is correct! but it's too slow when running crystal4.in

