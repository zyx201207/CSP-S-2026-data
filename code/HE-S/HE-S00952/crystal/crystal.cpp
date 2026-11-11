#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long n, m;
long long a[N];
int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	long long ma = -1;
	long long t = a[1];
	
	if(a[1] > m){
		cout << 0;
		return 0;
	}
	while(t <= a[n]){ 
		t++;
		long long cnt = 0;
		
		long long m1 = m;
		for(int i = 1; i <= n; i++){
			if(t >= a[i] && m1 - (t - a[i]) >= 0){
				m1 -= (t - a[i]);
				cnt++;
			}
		}
		ma = max(ma, cnt);
	}
	
	cout << ma;
	return 0;
} 
