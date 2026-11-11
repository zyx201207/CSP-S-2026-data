#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],v[300005],b[500005],c[300005],vis[300005],pre[300005];
void f(ll x){
	ll e=0;
	for(ll i=1;i<=n;i++){
		b[i]=0;
	}
	for(ll i=1;i<=m;i++){
		v[i]=0;
		vis[i]=0;
	}
	for(ll i=x;i<=n;i++){
		if(v[a[i]]!=0){
			ll tmp=e;
			e=v[a[i]]-1;
			for(ll j=v[a[i]];j<=tmp;j++){
				v[b[j]]=0;
			}
		}
		b[++e]=a[i];
		v[a[i]]=e;
	}
	for(ll i=1;i<=e;i++){
		if(!vis[b[i]]){
			c[b[i]]++;
			vis[b[i]]=1;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	ll flag=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]){
			pre[a[i]]++;
		}
		else{
			pre[a[i]]=pre[a[i-1]]+1;
		}
		if(a[i]<a[i-1]){
			flag=0;
		}
	}
	if(flag==1){
		ll maxx=0;
		for(ll i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		for(ll i=1;i<=m;i++){
			if(i<=maxx){
				cout<<pre[i]<<' ';
			}
			else{
				cout<<"0 ";
			}
		}
		return 0;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		f(i);
	}
	for(ll i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}