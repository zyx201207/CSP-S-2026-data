#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("and5.in","r",stdin);
	freopen("and5.out","w",stdout); 
	long long n,m;
	cin >> n >> m;
	long long a[n];
	for (long long i = 0;i < n; i++ ){
		cin >> a[i];
	}
	sort(a,a + n,cmp);
	long long ans = (a[0]) & (a[1]);
	for (long long i = 1;i < m;i ++ ){
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
