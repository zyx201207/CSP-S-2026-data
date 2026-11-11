#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long a;
	char b;
	string s = "";
	cin >> n;
	int m = n;
	long long l = 0;
	long long ans = 0;
	char g[100005];
	long long v[100005];
	while(m--){
		cin >> a >> b;
		l += a;
		v[n-m-1] = a;
		g[n-m-1] = b;
	}
	for(int i = 0; i < n; i++){
		if(g[i] != g[n-1]){
			if(v[i] > v[n-1]){
				ans += v[n-1];
				v[i] -= v[n-1];
				n--;
				i--;
			}else if(v[i] == v[n-1]){
				n--;
				ans += v[i];
			}else{
				ans += v[i];
				v[n-1] -= v[i];
			}
		}else{
			if(v[i] > v[n-1]){
				v[i] -= v[n-1];
				n--;
				i--;
			}else if(v[i] == v[n-1]){
				n--;
			}else{
				v[n-1] -= v[i];
			}
		}
	}
	cout << ans;
	return 0;
}
