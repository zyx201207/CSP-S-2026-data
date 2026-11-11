#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n; 
ll m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n >>m;
	vector<ll> a(n+1),q(n+1);
	for(int i=1;i<=n;i++) cin >>a[i];
	sort(a.begin(),a.end());
	for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	ll l=1,r=1,ans=0;
	while(r<=n){
		ll sum=a[r]*(r-l)-q[r-1];
		if(sum>m && l<r) l++;
     	else if(sum<=m) ans=max(ans,r-l+1), r++;
	}
	cout <<ans;
}
 
