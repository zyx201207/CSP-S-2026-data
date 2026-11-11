//GZ-S00327 夏宇森 中央民族大学附属中学贵阳学校 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6;
int n;
ll m;
ll a[N], s[N];
bool cmp(ll x1, ll x2){
	return x1 < x2;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d", &n, &m);
	a[0] = 0; s[0] = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1,cmp);
	int l = 1, r = 1, maxcnt = 0, cnt = 1;
	ll now = 0;
	while(r<=n){
		r++;
		if(r > n) break;
		now +=(a[r] - a[r-1]) * cnt;
		if(now > m){
			now -= (a[r] - a[l]);
			l++;
		}else{
			cnt++;
		}
		maxcnt = (cnt>maxcnt)? cnt:maxcnt;
	}
	cout << maxcnt;
	return 0;
}
