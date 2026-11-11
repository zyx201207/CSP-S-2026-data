#include<bits/stdc++.h>
using namespace std ;
long long a[200005] ;
char c[200005] ;
int main() {
	freopen("string.in" ,"r" ,stdin ) ;
	freopen("string.out" ,"w" ,stdout ) ;
	long long n ;
	cin >> n ;
	long long sum = 1 ;
	long long m = n ;
	long long cnt = 0 ;
	for(int i = 1 ;i <= n ;i++ ) {
		cin >> a[i] >> c[i] ;
		sum += a[i] ;
	}
	long long j = 0 ;
	long long ans = 0 ;
	while(1) {
		j++ ;
		long long o = sum ;
		cnt += a[j] ;
		if(o <= cnt ) break ;
		while(1) {
			if(sum - a[m] >= o - a[j] ) {
				sum -= a[m] ;
				if(c[m] != c[j]) ans += a[m] ;
				m-- ;
			}
			else {
				if(c[m] != c[j]) ans += sum - o + a[j] ;
				a[m] = a[m] - sum + o - a[j] ;
				sum = o - a[j] ;
				break ;
			}
		}
	}
	cout << ans ;



	return 0 ;
}

