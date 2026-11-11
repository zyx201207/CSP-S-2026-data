#include <bits/stdc++.h>
using namespace std;

long long a[500004];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	long long m, n, ans=1;
	cin >> n >> m;
	for(int i=1; i<=n; i++) 
		cin >>a[i];
	long long num=abs(a[3]-a[2]);
	while(m-num>=0){
		if(ans >= n)
			break;
		m-=num;
		num+=abs(a[3]-a[2]);
		ans++;
	}
	cout << ans;	
	return 0;
}
