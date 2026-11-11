#include <bits/stdc++.h>
using namespace std;
long long s[200005];
long long  xp(long long m, int i){
	if(m > 1) xp(m-1,i+1);
	return s[i] & s[i+1];
}
int main(){
	freopen("and.in", "r",stdin);
	freopen("and.out","w",stdout);
	long long  n, m, ma = 0, ma1 = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		ma1 = max(ma1,s[i]);
	}
	for(int i = 1; i < n - m+1; i++){
		long long a = xp(m,i);
		ma = max(a,ma);
	}
	if(m == 1) {
		cout << ma1;
		return 0;
	}
	cout << ma;
	return 0;
}
