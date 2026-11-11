#include <bits/stdc++.h>
using namespace std;

long long n, m, l, sum, cnt, ans, a[500005], c[500005];
int main(){
		
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i = 0; i < n; ++i){
		cin>>a[i];
	}
	sort(a, a+n);
	
	for(int i = 1; i < n; ++i){
		c[i] = a[i] - a[i-1];
		sum += c[i];
		cnt += (i-l)*c[i];
		
		while(l < i && cnt > m){
			cnt -= sum;
			sum -= c[++l];
		}
		
		ans = max(ans, i-l);
	}
	cout<<ans+1;
	return 0;
}
