#include<bits/stdc++.h>

using namespace std;

#define int long long
int a[200005],n,m,ans ;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m ;
	for(int i=1;i<=n;i++) cin >> a[i] ;
	sort(a+1,a+n+1);
	cout << a[n-m+1] << '\n' ;
	return 0 ;
}
