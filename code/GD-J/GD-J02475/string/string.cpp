#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a;
	long long cnt=0;
	string e;
	string x;
	cin >> n;
	if (n==1){
		cout << 0;
		return 0;
	} 
	for(long long i=0; i<n; i++){
		cin >> a >> x;
		for(long long j=0; j<a; j++){
			e += x;
		}
	}
	long long k = e.size();
	for(long long i= k-1; i > k/2; i--){
		if(e[i] != e[k-i-1])cnt++;
	}
	 cout  << cnt;
	return 0;
} 
