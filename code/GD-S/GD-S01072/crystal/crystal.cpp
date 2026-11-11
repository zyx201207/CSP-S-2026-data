#include <bits/stdc++.h>
using namespace std;

int n, tmp;
long long a[500005], m, ans;
//bool b[500005];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) a[i] -= a[i - 1];
	ans = 1, m--;
	for(int i = 1; i < n; i++) for(int j = 0; j <= m; j++)if(j == a[i]){
		ans++;
		m -= j;
		break;
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
