#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200005];
ll maxx=-1,jans;
bool ta=true;
bool po(ll x){
	while(x!=0){
		if(x%2==0){
			return false;
		}x/=2;
	}return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(ta&&po(a[i])){
			ta=false;
		}
		if(i==1){
			jans=a[i];
		}else{
			jans=(jans&a[i]);
		}
		maxx=max(maxx,a[i]);
	}if(m==1){
		cout<<maxx;
	}else if(m==n){
		cout<<jans;
	}else if(m==2){
		ll tans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				tans=max(tans,(a[i]&a[j]));
			}
		}
		cout<<tans;
	}else if(ta==true){
		sort(a+1,a+n+1,greater<ll>());
		ll jjan=a[1];
		for(int i=1;i<=m;i++){
			jjan=(jjan&a[i]);
		}
		cout<<jjan;
	}else{
		cout<<maxx;
	}
	return 0;
}
