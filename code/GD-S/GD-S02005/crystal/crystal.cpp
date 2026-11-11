#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500009],s[500009];
bool check(int x){
	int l = 1,r = x;
	int mn = 1e18;
	while(r<=n){
		mn = min(mn,(a[r]*x)-(s[r]-s[l-1]));
		l++,r++;
	}
	return mn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;++i){
		s[i] = s[i-1]+a[i];
	}
	int l = 1,r = n;
	while(l<r){
		int mid = ((l+r)/2)+1;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	cout<<l;
}
