#include<bits/stdc++.h>
#define int long long
#define N 500005

using namespace std;

int n,m,l,r,a[N];

bool check(int x){
	int mn = 1e18;
	for(int i = 1;i <= n - x + 1;i++){
		mn = min(mn,x * (a[i + x - 1] - a[i + x - 2]) - (a[i + x - 1] - a[i - 1])); 
	}
	if(mn <= m)return 1;
	else return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	l = 1,r = n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)a[i] += a[i - 1];
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid))l = mid;
		else r = mid - 1;
	}
	cout << l << "\n";
	return 0;
}
