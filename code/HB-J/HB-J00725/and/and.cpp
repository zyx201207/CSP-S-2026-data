#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<ll>());
	ll ans=0;
	for(int l=1,r=l+m-1;r<=n;l++,r++){
		ll k=a[l];
		for(int i=l;i<=r;i++){
			k=k&a[i];
		}
		ans=max(k,ans);
	}
	cout<<ans;
	return 0;
}
