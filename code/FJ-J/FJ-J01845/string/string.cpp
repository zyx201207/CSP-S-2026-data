#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n,a,d = 0,f = 1,ans = 0;
	char c;
	string b;
	cin >> n;
	for(long long i = 0;i < n;i++){
		cin >> a >> c;
		d += a;
		for(long long j = 0;j < a;j++){
			b += c;
		}
	}
	if(d % 2 == 1) f = 0;
	d /= 2;
	for(long long i = 0,j = d * 2 - f;i < d;i++,j--){
		if(b[i] != b[j]){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
