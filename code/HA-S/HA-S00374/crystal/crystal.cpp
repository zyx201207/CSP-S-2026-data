#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+55;
ll a[N],c[N];
ll n,m;
bool check(ll x){
	for(int i=x;i<=n;i++){
		ll sum=0;
		for(int j=i-1;j>i-x;j--){
			sum+=c[j]*(ll)(j-(ll)(i-x));
			if(sum>m){
				break;
			}
		}
		if(sum<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	ll l=1,r=n,res=1;
	while(l+1<r){
		ll mid=(l+r)/2;
		if(check(mid)){
			l=mid;
			res=mid;
		}else{
			r=mid;
		}
	}
	if(check(n))cout<<n;
	else cout<<res;
	return 0;
}
