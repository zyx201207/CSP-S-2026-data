#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, ans, now = 0, k = 1;
	cin >> n >> m;
	vector<long long>a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<long long>b(n);
	b[0] = 0;
	while(now <= m){
		ans = k;
		b[k] = b[k-1] + (k * (a[k]-a[k-1]));
		now = b[k];
		k++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
