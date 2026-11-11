//GZ-S00020 郑淇予 贵阳市第一中学 
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ll long long
using namespace std;
const int N = 500005;
ll a[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n;
	ll m;
	scanf("%lld%lld", &n, &m);
	FOR(i, 1, n){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	ll sum = 0, ans = 1, s = 1;
	FOR(i, 2, n){
		sum += (a[i]-a[i-1])*(i-s);
		while(sum > m && s < i){
			sum -= (a[i]-a[s]);
			s++;
		}
		//cout << i << '#' << sum << '#' << s << endl; 
		if(s < i)ans = max(ans, i-s+1);
	}
	printf("%lld", ans);
	return 0;
}
