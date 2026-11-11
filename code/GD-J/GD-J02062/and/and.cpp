#include<bits/stdc++.h>
using namespace std;
long long twopo(long long n){
	long long tee = 0,o = 1;
	while(n > 0){
		tee += n % 2 * o;
		o *= 10;
		n /= 2;
	}
	return tee;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	long long maxand = 0;
	cin >> n >> m;
	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0 ; i < n; i++){
		for(int j = i + 1; j < n; j++){
			maxand = max(maxand,(a[i] & a[j]));
		}
	}
	cout << maxand;
	return 0;
}
