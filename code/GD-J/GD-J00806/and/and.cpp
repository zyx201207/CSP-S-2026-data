#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[1000010];
ll tot,mx,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) tot=a[i];
		tot=(tot&a[i]);
		mx=max(mx,a[i]);
	}if(m==1){
		cout<<mx;
		return 0;
	}if(m==n){
		cout<<tot;
		return 0;
	}if(m==2){
		if(n<=10086){
			mx=0;
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					if(i==1&&j==2) mx=(a[i]&a[j]);
					mx=max(mx,(a[i]&a[j]));
				}
			}
		}cout<<mx;
		return 0;
	}if(n<=9718&&m==n-1){
		ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i==j) continue;
				if(j==1) ans=a[j];
				ans=(ans&a[j]);
			}
		}cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=n;i>=n-m+1;i--){
		if(i==n) ans=a[i];
		ans=(ans&a[i]);
	}cout<<ans;
	return 0;
}
