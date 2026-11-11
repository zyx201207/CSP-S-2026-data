#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int read(){
	int t = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return f * t;
}
int n, m;
const int N = 5e5 + 10; 
int a[N];
int sum[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read();
	m = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();		
	}	
	sort(a + 1, a + 1 + n);
	int val = 0;
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int j = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		while(j < i && a[i] * (i - j + 1) - sum[i] + sum[j - 1] > m) j++;
		ans = max(ans, i - j + 1); 
	}
	cout << ans;
	return 0;
}
