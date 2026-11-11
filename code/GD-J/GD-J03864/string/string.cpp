#include <bits/stdc++.h>
using namespace std;

struct Node{
	long long a;
	char c;
}node[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	long long sum = 0, sum1 = 0;
	for (int i = 1; i <= n; i++){
		cin >> node[i].a >> node[i].c;
		sum += node[i].a;
		for (int j = 1; j <= node[i].a; j++){
			s += node[i].c;
		}
	}
	long long ans = 0;
	if (sum % 2 == 0){
		long long mid1 = sum / 2 - 1;
		long long mid2 = sum / 2;
		for (int i = mid1; i >= 0; i--){
			if (s[i] != s[mid2 + (mid1 - i)]){
				ans ++;
			}
		}
	}
	else{
		long long mid = sum / 2;
		for (int i = mid; i >= 0; i--){
			if (s[i] != s[mid + (mid - i)]){
				ans ++;
			}
		}
	}
	cout << ans;
	return 0;
}

