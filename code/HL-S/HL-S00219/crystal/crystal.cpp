#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in",'r',stdin);
	freopen("crystal.out",'w',stdout);
	long long n,m;
	cin >> n >> m;
	long long a[n];
	for (long long i = 0;i < n;i++){
		cin >> a[i];
	}
	long long a1 = a[0],a2 = a[1];
	long long u = abs(a1 - a2);
	long long sum = m,ans = 0;
	for (long long i = 0;;i += u){
		sum -= i;
		if (sum < 0){
			cout << ans;
			return 0;
		}
		ans++;
	}
}
