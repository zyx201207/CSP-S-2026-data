#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],t[5];
struct node{
	ll c[35],id;
	bool operator<(const node &n2)const{
		for(ll i=0;i<=30;i++){
			if(c[i]!=n2.c[i]){
				return c[i]>n2.c[i];
			}
		}
		return c[30]>n2.c[30];
	}
}b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	ll n,m;
	cin>>n>>m;
	if(m==1){
		ll maxx=-1;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		ll maxx=-1;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		ll ans=a[1];
		for(ll i=1;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	ll maxxx=-1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxxx=max(maxxx,a[i]);
		b[i].id=i;
		for(ll j=30;j>=0;j--){
			b[i].c[30-j]=(a[i]>>j)&1;
		}
	}
	if(maxxx<4){
		for(ll i=1;i<=n;i++){
			t[a[i]]++;
		}
		if(t[3]>=m){
			cout<<3;
		}
		else if(t[3]+t[2]>=m){
			cout<<2;
		}
		else if(t[3]+t[1]>=m){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	sort(b+1,b+n+1);
	ll ans=a[b[1].id];
	for(ll i=1;i<=m;i++){
		ans=(ans&a[b[i].id]);
	}
	cout<<ans;
	return 0;
}