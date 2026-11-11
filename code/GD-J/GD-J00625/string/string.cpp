#include<bits/stdc++.h>
#define N 200007
#define ll long long
using namespace std;
int a[N], n;
char c[N];
ll len(ll l1, ll r1, ll l2, ll r2){
	return max(min(r1, r2) - max(l1, l2) + 1, 0LL);
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int p = 1, q = n;
	ll lp = 1, lq = 1, ans = 0;
	while(p < q){
		ll rp = lp + a[p] - 1, rq = lq + a[q] - 1;
		ll congh = len(lp, rp, lq, rq);
		if(c[p] == c[q]){
			
		}
		else{
			ans += congh;
		}
		if(rp < rq){
			lp += a[p];
			p++;
		}
		else{
			lq += a[q];
			q--;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
