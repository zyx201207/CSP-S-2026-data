#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	int n;
	cin >> n;
	string ans = "";
	for (int i = 1; i <= n; i++){
		int m;
		cin >> m;
		char x;
		cin >> x;
		for (int j = 1; j <= m; j++){
			ans += x;
		}
	}
	long long s = ans.size();
	int cnt = 0;
	for (long long i = 0; i < s / 2; i++){
		if (ans[i] != ans[s - i + 1]){
			cnt++;
		}
			
	}
	cout << cnt << endl;
	return 0;
} 
