#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
#define si short int
using namespace std;
const int N=2e5+9;
ll n,m;
ll ans=0;
ll a[N];
void dfs(ll idx,ll val,ll k) {
	if(k==m) {
		ans=max(ans,val);
		return;
	}
	else if(idx==n) return;
	dfs(idx+1,val&a[idx],k+1);
	dfs(idx+1,val,k);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20) {
		for(ll i=0;i<n;i++) {
			cin>>a[i];
		}
		dfs(0,(1<<30)-1,0);
		cout<<ans;
	}
	else if(m==1) {
		for(ll i=0;i<n;i++) {
			ll x;
			cin>>x;
			ans=max(ans,x);
		}
		cout<<ans;
	}
	else if(m==2) {
		for(ll i=0;i<n;i++) {
			cin>>a[i];
		}
		for(ll i=0;i<n;i++) {
			for(ll j=i+1;j<n;j++) {
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n) {
		ans=(1<<30)-1;
		for(ll i=0;i<n;i++) {
			ll x;
			cin>>x;
			ans&=x;
		}
		cout<<ans;
	}
	else {
		for(ll i=0;i<n;i++) {
			cin>>a[i];
		}
		sort(a,a+n,[](ll aa,ll bb)->bool{return aa>bb;});
		ans=(1<<30)-1;
		for(ll i=0;i<m;i++) {
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}

/*
6p
*/

/*
2 2
4
4

5 3
31 3 1 15 7
*/
