#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int N = 2e6+10;
long long ans, cur, a[N];
int n;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++){
		int ai, id;
		cin >> ai;
		char c;
		cin >> c;
		id = c-'a'+1;
		for (int j = 1; j <= ai; j++){
			a[++cur] = id;
		}
	}
	for (int i = 1; (cur-i+1) > i; i++){
		if (a[i] != a[cur-i+1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
