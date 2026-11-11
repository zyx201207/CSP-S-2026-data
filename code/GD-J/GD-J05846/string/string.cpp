#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+9;
int a[M];
char s[M], d[M];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n; cin >> n;
	long long cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> s[i];
		cnt += a[i];
	}
	for(int i = 1; i <= cnt; i++){
		for(int j = 1; j <= a[i]; j++){
			d[i] = s[i];
		}
	}
	long long ans = 0; 
	for(int i = 1; i <= cnt; i++){
		if(d[i] == d[cnt-i+1]) continue;
		else if(d[i] != d[cnt-i+1]){
			d[cnt-i+1] = d[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
