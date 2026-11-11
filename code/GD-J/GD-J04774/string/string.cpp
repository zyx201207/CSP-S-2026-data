#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int MAXM = 4e5 + 7;
int n, l = 1;
int a[MAXN], s[MAXN], cnt;
char c[MAXN], cl[MAXN];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "a", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for(int j = l; j <= l + a[i]; j++){
			cl[j] = c[i];
		}
		l += a[i];
		s[i] += a[i] + s[i - 1];
	}
	for(int i = 1; i <= s[n] / 2; i++){
		if(cl[i] != cl[s[n] - i + 1])cnt++;
	}
	cout << cnt;
	return 0;
}
