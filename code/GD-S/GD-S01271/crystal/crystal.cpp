#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
using ll=long long;

ll pre[N];
ll a[N];
ll n,m;
bool check(int x){
	for(ll i=1;i+x-1<=n;i++){
		ll cnt=0;
		cnt=a[i+x-1]*(x-1)-(pre[i+x-2]-pre[i-1]);
		if(cnt<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	ll l=1,r=n;
	ll ans=0;
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
} 
