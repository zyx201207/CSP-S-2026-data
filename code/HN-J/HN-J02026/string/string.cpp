#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, a[N];
char c[N];
long long s[N], cnt;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i] >> c[i];
		s[i] = s[i-1]+a[i];
	}
	cnt = s[n];
	int k1 = 1, k2 = n;
	long long cntt = cnt/2;
	long long ans = 0;
	for(long long i = 1;i <= cntt && k1 <= n && k2 >= 1;i ++){
		long long l = i, r = cnt-i+1;
		if(l > s[k1]){k1 ++;}
		if(r < s[k2]){k2 --;}
		if(k1 > n || k2 < 1){
			break;
		}
		if(c[k1] != c[k2]){
			ans ++; 
		}
	}
	cout << ans;
	return 0;
}
