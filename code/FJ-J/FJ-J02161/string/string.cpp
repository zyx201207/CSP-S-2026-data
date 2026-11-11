#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 +10;
int n;
long long a[N];
char c[N], s[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	bool f = 0;
	long long cnt = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
		s[i + cnt] = c[i];
		cnt += a[i];
		if(c[i] != c[i - 1] && i != 1){
			f = 1;
		}
	}
	if(f == 0){
		cout << 0;
		return 0;
	}
	for(long long i = 2; i <= cnt; i++){
		if(!s[i]) s[i] = s[i - 1];
	}
	long long ans = 0;
	for(long long i = 1; i <= cnt / 2; i++){
		if(s[i] != s[cnt - i + 1]) ans ++;
	}
	cout << ans << endl;
	return 0;
}
