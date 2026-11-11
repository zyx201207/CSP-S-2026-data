#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

long long a[N];

int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	
	sort(a+1, a+n+1);
	
	int ans = 0;
	long long res = 0;
	int j = 1;
	
	for(int i = 2; i <= n; i++){
		res += (i - j) * 1ll * (a[i] - a[i-1]);
		
		while(res > m){
			res -= a[i] - a[j];
			j++;
		}
		
		ans = max(ans, i - j + 1);
	}
	
	cout << ans;
	
	return 0;
}
