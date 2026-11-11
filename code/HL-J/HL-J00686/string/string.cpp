#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n,a[100005],num = 0,sum,ans = 0;
	char c[100005];
	string s = "",s1 = "";
	bool b = true;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++){
			s+=c[i];
		}
		num+=a[i];
	}
	sum = num/2;
	for (int i = num-1; i > sum; i--){
		s1+=s[i];
	}
	for (int i = 0; i < sum; i++){
		if (s[i] != s1[i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
