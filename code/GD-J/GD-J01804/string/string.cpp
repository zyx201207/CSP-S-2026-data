#include<bits/stdc++.h>
using namespace std;
char a[200007];
int tot = 0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		char c;
		cin >> x >> c;
		for(int j = 1; j <= x; j++){
			tot++;
			a[tot] = c;
		}
	}
	for(int i = 1; i <= tot / 2; i++){
		if(a[i] != a[tot - i + 1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
