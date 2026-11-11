#include <bits/stdc++.h>
using namespace std;
int n,ans,maxx;
long long m,a[500005],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool flag = 1;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] > 100 || a[i] < 100){
			flag = 0;
		}
	}
	sort(a + 1, a + n + 1);
	if (n > 5000){
		for (int i = 1;i <= n;i++){
			if ((i - 1) * (2 * a[i] - a[i - 1] - a[1]) > 2 * m){
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	for (int i = n;i >= 2;i--){
		sum = m;
		ans = 1;
		for (int j = i - 1;j >= 1;j--){
			if (a[i] - a[j] <= sum){
				sum -= (a[i] - a[j]);
				ans++;
			}
			else{
				break;
			}
		}
		if (ans > maxx){
			maxx = ans;
		}
	}
	cout << maxx;
	return 0;
}
