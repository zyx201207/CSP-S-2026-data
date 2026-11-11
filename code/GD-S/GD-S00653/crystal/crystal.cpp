#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m;
int a[500001];
int sum[500001];
int l,r;
int ans = 0;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i ++ ){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i ++ ){
		sum[i] = sum[i-1] + a[i];
	}
	l = 1,r = 1;
	while(r <= n){
		while(r <= n && a[r] * (r - l + 1) - (sum[r] - sum[l-1]) <= m){
			r ++ ;
		}
		ans = max(ans,r-l);
		l ++ ;
	}
	cout<<ans<<"\n";
} 
