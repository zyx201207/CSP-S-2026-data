#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long n, m, a[N], sum; 
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if(a[2] == a[3]) {
		cout << a[2]- a[1];
		return 0;
	}
	sum = abs(a[1] + a[2]);
	cout << sum;
	return 0;
}
