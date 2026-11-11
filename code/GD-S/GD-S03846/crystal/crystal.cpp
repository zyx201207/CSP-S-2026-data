#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;

const int N = 1e6 + 10;

int a[N];

int num[N];

signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	
	for(int i = 1 ; i < n ; i ++){
		num[i] = a[n] - a[i];
	}
	
	sort(num + 1, num + 1 + n);
	
	int ans = 0;
	int sum = 0;
	
	for(int i = 1 ; i <= n ; i ++){
		sum += num[i];
		
		if(sum <= m)
			ans ++;
	}
	
	cout << ans;
		
	return 0;
}

