#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5+10;
ll a[N],b[2*N],sum[N];
char c[N],d[2*N];
int n;

int get(ll x){
	int l = 1,r = n;
	while(l<r){
		int mid = (l+r)>>1;
		if(sum[mid]<x)
			l = mid+1;
		else
			r = mid;
	}
	return l;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		sum[i] = sum[i-1]+a[i];
	}
	ll l = 1,r = sum[n],ans = 0;
	while(l<r){
		int x = get(l),y = get(r);
		if(x==y)
			break;
		ll jump = min(sum[x]-l+1,r-sum[y-1]);
		if(c[x]!=c[y])
			ans += jump;
		l += jump;
		r -= jump;
	}
	cout << ans;
	return 0;
}
