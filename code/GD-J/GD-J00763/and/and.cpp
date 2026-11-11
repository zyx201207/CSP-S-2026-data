#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string x,y;
bool p,l,e;
ll n,m,o,r;
ll s[200010],f[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		
	}
	if(m==1){
		for(ll i=1;i<=n;i++){
			o=max(o,s[i]);
		}
		cout<<o;
		exit(0);
	}
	else if(m==n){
		o=s[1];
		for(ll i=2;i<=n;i++){
			o=o&s[i];
		}
		cout<<o;
		exit(0);
	}
	else if(n<=20 and m<=n){
		sort(s+1,s+1+n,greater<ll>());
		o=s[1];
		for(ll i=2;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ll u=m;
				for(ll u=j;u<=m;u++){
					o=max(o&s[u],s[i]&s[u]);
				}
				r=max(o,r);
				o=1;
			}
		}cout<<r;
		exit(0);
	}
	else if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				o=max(s[i]&s[j],o);
			}
		}cout<<o;
		exit(0);
	}
	else{
		sort(s+1,s+1+n,greater<ll>());
		o=1;
		for(ll i=1;i<=m;i++){
			o=o&s[i];
		}
		cout<<o;
		exit(0);
	}
	
	return 0;
}
