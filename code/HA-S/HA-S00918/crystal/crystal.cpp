#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5e5 + 10;

int n, m;
ll a[N], s[N];
int t[N], mp[N];
vector<ll> v;
int ans;

int suan(int pos, int x){
	int l = 1, r = pos - 1;
	int res = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(a[pos] * (pos - mid) - s[pos - 1] + s[mid - 1] <= (ll)m){
			res = mid;
			r = mid - 1;
		}else
			l = mid + 1;
	}
	return pos - res + t[x];
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
		v.push_back(a[i]);
	}
	sort(a + 1, a + 1 + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1;i <= n;i++){
		int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		t[x]++, mp[i] = x;
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i++){
		if(i != 1 && a[i] == a[i - 1])	continue;
		ans = max(ans, suan(i, mp[i]));
	}
	printf("%d", ans);
	return 0;
}
/*
	15:12 let's go!!!
*/
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
