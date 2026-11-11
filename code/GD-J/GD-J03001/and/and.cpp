#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

long long a[N];

bool cmp(long long a, long long b){
	return a > b;
}

int main(){
	
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a+1, a+n+1, cmp);
	
	long long ans = a[1];
	
	for(int i = 1; i <= m; i++){
		ans = ans & a[i];
	}
	
	cout << ans;
	
	return 0;
}
