#include<bits/stdc++.h>//crystal
using namespace std;
#define ll long long
#define vv vector
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vv<ll> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	ll res=0,ans=0;
	for(int r=0;r<n;r++){
		int l=r;
		ll sum=0;
		while(l>=0&&sum<=m){
			l--;
			sum+=a[r]-a[l];
			ans++;
		}
		res=max(ans,res);
		ans=0;
	}
	cout<<res;
	return 0;
}
/*
5 8 
-3 -1 2 2 7

5 5
1 2 4 8 9

9 5 
-1 -2 -4 -6 1 2 3 4 5
*/

