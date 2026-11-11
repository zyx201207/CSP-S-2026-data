#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, num = 0, ans = 0;
	char c;
	cin >> n;
	vector<long long>a(n + 1);
	char S[50000];
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c;
		for(int j = num + 1; j <= num + a[i]; j++){
			S[j] = c;
		}
		num += a[i];
	}
	for(int i = 1; i <= (num + 1) / 2; i++){
		if(S[i] != S[num + 1 - i]){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
