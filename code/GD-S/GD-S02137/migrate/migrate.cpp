#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e6+10;
ll a[N];
ll n,m;

void solve1(){
	ll k = abs(a[2]-a[1]);
	ll t = m/k;
	if(t<2)
		cout << "0\n";
	else
		cout << max(n-t*2+1,(ll)0) << '\n';
}

void solve2(){
	ll ans = 0;
	for(int i=2;i+2<=n;i++){
		int l = 1,r = i-1;
		while(l<r){
			int mid = (l+r)/2;
			if(abs(a[mid]-a[i+1])<=m)
				r = mid;
			else
				l = mid+1;
		}
		if(!(abs(a[l]-a[i+1])<=m&&abs(a[l]-a[i+2])>m))
			continue;
		int j = l;
		l = i+2,r = n;
		while(l<r){
			int mid = (l+r+1)/2;
			if(abs(a[mid]-a[i])<=m)
				l = mid;
			else
				r = mid-1;
		}
		if(!(abs(a[l]-a[i])<=m&&abs(a[l]-a[i-1])>m))
			continue;
		int k = l;
		int p1 = j,p2 = k;
		while(p1>1&&abs(a[p1-1]-a[p1])<=m&&(p1==2||abs(a[p1-2]-a[p1])>m))
			p1--;
		while(p2<n&&abs(a[p2+1]-a[p2])<=m&&(p2==n-1||abs(a[p2+2]-a[p2])>m))
			p2++;
		cout << p1 << " " << j << " " << k << " " << p2 << '\n';
		ans += (j-p1+1)*(p2-k+1);
	}
	cout << ans << '\n';
}

void solve(){
	cin >> n >> m;
	bool flag = true;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
			flag = false;
	}
	if(flag)
		solve1();
	else
		solve2();
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
		solve();
	return 0;
}
