#include<bits/stdc++.h>
using namespace std;
const long long N = 555555;
long long a[N];
long long b[N];
long long m;
long long n;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","l",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i = 1 ; i <= n ; i ++){
		cin>>a[i];
	}
	for(long long i = 2 ; i <= n ; i++){
		for(long long j = 1 ; j <= i ; j++){
			b[i] = b[i] + a[i] - a[j];
		}
	}
	for(long long i = n ; i >= 0 ; i--){
		if(b[i] <= m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
