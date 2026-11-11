#include<bits/stdc++.h> 
#define int long long
using namespace std;

const int N = 5e5 + 100;

int n, m, a[N], need, l, ans = 1;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;i ++)cin >> a[i];
	
	sort(a+1,a+1+n);
	
	l = 1;
	
	for(int r = 1;r <= n;r ++){
		need = need + (r - l) * (a[r] - a[r - 1]);
		
		while(need > m){
			need -= (a[r] - a[l]);
			l ++;
		}
		
		ans=max({ans,r - l + 1});
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
