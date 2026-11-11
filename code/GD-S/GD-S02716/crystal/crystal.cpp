#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+8;
const int mod =998244353;
#define ll long long
ll a[mx];
void solve(){
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	int l=1,r=1;
	ll res=0;
	while(r<n){
//		if(l==r&&r<n)r++;
		while(r<n){
			if(r<n&&res+(r+1-l)*(a[r+1]-a[r])<=m){
				res+=(r+1-l)*(a[r+1]-a[r]);
				r++;
			}
			else break;
		}
		if(res<=m)ans=max(r-l+1,ans);
		res-=a[r]-a[l];
		if(l==r&&r<n){
			r++;
			res=0;
		}
		l++;
	}
	cout<<ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


