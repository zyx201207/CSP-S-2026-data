#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
string s;

const int N = 5e6;

int a[N];
char c[N];

int sum;

signed main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] >> c[i];
	}
	
	int ans = 0;
		
	for(int i = 1 ; i <= n; i ++){
		if(c[i] != c[n - i + 1])
			ans += max(a[i], a[n - i + 1]);
	}
	
	cout << ans / 2; 
	
	return 0;
}
