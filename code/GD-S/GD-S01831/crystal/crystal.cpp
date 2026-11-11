#include<bits/stdc++.h>
using namespace std;
const long long N = 500001;
long long a[N];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	long long n , m , s = 1;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int k = a[n];
	while(m){
		if(a[n] + m < k) break;
		n--;
		if(a[n] + m == k){
			s++;
			m = 0;
		}
		if(a[n] + m > k){
			s++;
			m = m + a[n] - k;
		}
	}
	cout << s;
	return 0;
}
