#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
long long a[500005];
long long b[500005];
int n, m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for(int i = 2; i <= n; i++){
		b[i] = a[i] - a[i-1];
	}
	int ans = 1;
	int sum = 0;
	int t = 1;
	for(int i = 2; i <= n; i++){
		sum += (t-1)*b[i];
		if(sum > m){
			sum = 0;
			ans = max(ans, t);
			t = 0;
		}
		t++;
	}
	cout << ans;
	return 0;
}
