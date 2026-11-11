#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];
char s[200005];
long long sum = 0, ans = 0;
    
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i ++){
		char c;
		cin >> a[i] >> c;
		for(int i = 1; i <= a[i]; i ++){
			sum ++;
			s[sum] = c;
		}
	}
	long long t = sum / 2;
	for(int i = 1; i <= t; i ++){
	    if(s[i] != s[sum - i + 1]){
			ans ++;
		}
	}
	cout << ans;
    return 0;
}
