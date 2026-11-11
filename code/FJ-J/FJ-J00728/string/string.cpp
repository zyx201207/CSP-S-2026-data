#include <bits/stdc++.h>
using namespace std;
int n, a[200001];
long long ans;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	int l = 1, r = n, ls = a[1], rs = a[n];
	while(l < r){
		if(c[l] != c[r]){
			ans += min(ls,rs);
		}
		if(ls > rs){
			ls -= rs;
			rs = a[--r];
		}else if(rs > ls){
			rs -= ls;
			ls = a[++l];
		}else{
			ls = a[++l];
			rs = a[--r];
		}
	}
	cout << ans;
	return 0;
}
