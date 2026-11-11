#include <bits/stdc++.h>
using namespace std;
int cmp(int a, b) { 
	return a > b;
}


int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n, m; 
	cin >> n >> m; 
	long long a[n]; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		
	}
	/*vector <long long> dp(m + 1, 0); 
	dp[1] = a[1]; 
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 2; j--) {
			dp[j] = max(dp[j], dp[j-1] & a[i]);
		}
	}*/
	sort(a + 1, a + n + 1,cmp);
	long long sum = a[1]; 
	for (int i = 2; i <= m + 1; i--){
		sum = sum ^ a[i]; 
		cout << sum << " ";
	} 
	cout << sum; 
	
	return 0;
}

