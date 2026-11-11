//GZ-J00592
//遵义市新蒲新区滨湖中学
//邓佳琪 
#include <bits/stdc++.h>
using namespace std;
int cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	
	int n, m;
	cin >> n >> m;
	long long a[n + 1];
	for (int i = 1;i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	vector<long long> dp(m + 1, 0);
	
	for (int i = 1;i <= n;i ++){
		for (int j = m; j >= 2; j --){
			dp[j] = max(dp[j], dp[j - 1] & a[i]);
		}
	}
	


	cout << a[m];
	return 0;
}

