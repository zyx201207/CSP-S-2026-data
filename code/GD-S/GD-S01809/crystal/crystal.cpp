#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n,m,ans=1;
bool ax,bx;
ll a[500010];

ll calc(ll mid){
	ll sum=0;
	for(ll i=1;i<=n;i++){
		if(a[i]>mid)break;
		ll num=0,ss=0;
		for(ll j=i;j<=n;j++){
			num+=abs(mid-a[j]);
			ss++;
			if(num>m){
				ss--;
				break;
			}
		}
		sum=max(sum,ss);
	}
	return sum;
}

void solve(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		if(i==1)continue;
		if(a[i]-1!=a[i-1])ax=1;
		if(i==2)continue;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])bx=1;
	}
	if(ax==0){
		ll i=1;
		while(m>=i){
			m-=i;
			ans++;
			i++;
			if(ans==n)break;
		}
		cout << ans;
		return;
	}
	else if(bx==0){
		ll sum=a[2]-a[1];
		ll i=sum;
		while(m>=i){
			m-=i;
			ans++;
			i+=sum;
			if(ans==n)break;
		}
		cout << ans;
		return;
	}
	else{
		sort(a+1,a+n+1);
		ll l=a[1],r=a[n],mid;
		while(l<=r){
			mid=(l+r)/2;
			ll sum=calc(mid);
			if(sum>ans){
				ans=sum;
				r=mid-1;
			}
			else l=mid+1;
		}
		cout << ans;
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
} 
