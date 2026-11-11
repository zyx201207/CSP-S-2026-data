#include<bits/stdc++.h>
using namespace std;
int a[300010];
char c[300010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long ans = 0;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	int t = 1, w = n;
	while(t < w){
		if(a[t] >= a[w]){
			if(c[t] != c[w]){
				ans += a[w];
			}
			a[t] -= a[w];
			w--;
			if(a[t] == 0){
				t++;
			}
		}else if(a[w] > a[t]){
			if(c[t] != c[w]){
				ans += a[t];
			}
			a[w] -= a[t];
			t++;
		}
	}
	cout << ans;
	return 0;
}
