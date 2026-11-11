#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 5e5+10;
ll a[N],sum[N]; 
ll n,m;

bool check(int x,int y){
	int len = y-x+1;
	int t = a[y]*len-(sum[y]-sum[x-1]);
	return t<=m;
}

ll solve(int x){
	int l = 1,r = x;
	while(l<r){
		int mid = (l+r)>>1;
		if(check(mid,x))
			r = mid;
		else
			l = mid+1;
	}
	return x-l+1;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i] = sum[i-1]+a[i];
	ll ans = 0;
	for(int i=1;i<=n;i++)
		ans = max(ans,solve(i));
	cout << ans;
	return 0;
} 
