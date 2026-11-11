#include<bits/stdc++.h>
using namespace std ;
vector<pair<long ,long >> r ;
vector<long long > r1 ;
long long t[200005] ;
vector<long long > w[105] ;
long long n ,m ;
long long e[105] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824} ;
void f(long long n1 ) {
	if(n1 == m ) {
		long long sum = t[r[1].first] ;
		for(int i = 1 ;i < r.size() ;i++ ) {
			sum &= t[r[i].first] ;
		}
		cout << sum ;
		return ;
	}
	bool flag = 1 ;
	for(int i = 2 ;i < r.size() ;i++ ) {
		if(r[i].second != r[i - 1].second ) flag = 0 ;
	}
	if(flag ) {
		long long sum = t[r[1].first] ;
		for(int i = 1 ;i < r.size() ;i++ ) {
			sum &= t[r[i].first] ;
		}
		cout << sum ;
		return ;
	}
	long long www = 0 ;
	for(int i = 0 ;i < r.size() ;i++ ) {
		long long iii = 0 ;
		while(e[iii] <= r[i].second) {
			iii++ ;
		}
		www = max(www ,iii - 1 ) ;
		r1.push_back(r[i].second - e[iii - 1]) ;
		for(int j = 1 ;j <= iii - 1 ;j++ ) {
			w[j].push_back(i) ;
		}
	}
	for(int i = www ;i >= 1 ;i-- ) {
		if(w[i].size() >= m ) {
			r.clear() ;
			for(int j = 0 ;j < w[i].size() ;j++ ) {
				r.push_back({w[i][j] + 1 ,r1[w[i][j]]}) ;
			}
			f(w[i].size()) ;
			return ;
		}
	}
}
int main() {
	freopen("and.in" ,"r" ,stdin ) ;
	freopen("and.out" ,"w" ,stdout ) ;
	cin >> n >> m ;
	long long www = 0 ;
	for(int i = 1 ;i <= n ;i++ ) {
		cin >> t[i] ;
		r.push_back({i ,t[i]}) ;
	}
	f(n) ;




	return 0 ;
}

