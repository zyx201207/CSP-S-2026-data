#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 500005
ll n, m, a[M], maxn = -1, cha;
bool A = true, B = true;

ll check(ll r){
	ll j = 0, sum = 0;
	for(int i = r;i >= 1;i--){
		sum += (a[i] - a[i - 1]) * (i - 1);
		if(sum > m) break;
		j++;
	}
	return j;
}

ll getsum(ll x){return ((x + 1) * x / 2) * cha;}

ll tf(){
	ll l = 1, r = n, mid, ans = 0;
	while(l <= r){
		mid = (l + r) >> 1;
		if(getsum(mid - 1) <= m) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	ll last;
	for(int i = 1;i <= n;i++){
		cin >> a[i], cha = a[i] - a[i - 1];
		if(a[i] != i) A = false;
		if(i >= 3 && last != cha) B = false;
		last = a[i] - a[i - 1];
	}
	if(A) cout << tf();
	else if(B) cout << tf();
	else {
		sort(a + 1, a + 1 + n);
		for(int i = 1;i <= n;i++) maxn = max(maxn, check(i));
		cout << maxn;
	}
	return 0;
} 
