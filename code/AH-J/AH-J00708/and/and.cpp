#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll a[N],js[5];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,maxn=0,ans=1,ok=1,f=1,g=1,cn=0;
	scanf("%lld %lld",&n,&m);
	ll x=n;
	while(x!=1 && ok){
		if(x%2==1){
			f=0;
			break;
		}
		cn++;
		x/=2;
	}
	cn++;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(g && a[i]<=4)	js[a[i]]++;
		else   g=0;
		if(f && a[i]!=i-1)	f=0;
		ll x=a[i]+1;
		while(x!=1 && ok){
			if(x%2==1){
				ok=0;
				break;
			}
			x/=2;
		}
	}
	sort(a+1,a+1+n);
	if(ok==1){
		cout<<a[n-m+1];
		return 0;
	}
	for(ll i=1;i<=30;i++)	ans*=2;
	ans--;
	ans*=2;
	ans++;
	if(f==1){
		ll x=ans;
		for(ll i=n;i>=n-m+1;i--)	x&=a[i];
		cout<<x;
		return 0;
	}
	if(g==1){
		ll maxn=0;
		for(ll i=4;i>=0;i--){
			if(js[i]>=m)	maxn=max(maxn,i);
		}
		for(ll i=0;i<=3;i++){
			for(ll j=i+1;j<=4;j++){
				if(js[i]+js[j]>=m)	maxn=max(maxn,i&j);
			}
		}
		cout<<maxn;
		return 0;
	}
	for(ll l=1;l<=n-m+1;l++){
		ll cnt=ans;
		for(ll j=l;j<=l+m-1;j++){
			cnt&=a[j];
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
