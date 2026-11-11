#include<bits/stdc++.h>

#define int long long

using namespace std;

int n, m;
int a[500005];
int s[500005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>> n >> m;
	for(int i = 1; i <= n; i++){
		cin>> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	
	int ans = 0;
	int j = 0;
	for(int i = 1; i <= n; i++){
		int sum = a[i] * (i - j);
		int tmp = s[i] - s[j];
		while(tmp + m < sum && j < n){
			j++;
			sum = a[i] * (i - j);
			tmp = s[i] - s[j];
		}
		ans = max(ans, i - j);
	}
	
	cout<< ans;
	
	return 0;
}

