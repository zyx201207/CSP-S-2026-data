#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	long long n,m;
	cin >> n >> m;
	for(long long i = 0; i < n; ++i){
		cin >> a[i];
	}
	long long l,r;
	long long maxn = -1;
	l = 0,r = 1;
	for(long long i = 0; i < n; ++i){
		long long b[1000005] = {};
		b[0] = a[l];
		l++;
		while(r <= n){
			for(long long j = 1; j < m; ++j){
				b[j] = a[r];
				r++;
			}
			long long ans = 1;
			for(long long j = 0; j < m; ++j){
				ans = ans & b[j];
			}
			maxn = max(maxn,ans);
		}
		r = l+1;
	}
	cout << maxn;
	
	return 0;
}
