#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, a[100000];
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool flag = true;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(i >= 1 && a[i] != a[i - 1]){
			flag = false;
		}
	}
	if(flag){
		cout << n;
		return 0;
	}
	sort(a, a + n);
	int add = 0,ans;
	for(int i = 1; i < n; i ++){
		add += (a[i] - a[i - 1]) * i;
		if(add <= m){
			ans = i + 1;
		}else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
