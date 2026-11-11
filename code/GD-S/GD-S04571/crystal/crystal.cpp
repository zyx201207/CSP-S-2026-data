#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 7;
long long a[maxn];
long long b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = b[i-1] + a[i];
	}
	b[n] = 0;
	sort(a+1,a+n+1);
	while (n >= 0){
		int mx = a[n];
		if (mx * (n-1) - b[n-1] <= m){
			cout << n;
			return 0;
		}
		n--;
	}
	cout << n;
	
	return 0;
} 
