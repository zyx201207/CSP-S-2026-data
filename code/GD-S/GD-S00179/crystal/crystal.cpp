#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
using ll=long long;
ll a[N];
ll n,m;
ll pre[N];
ll w[N],v[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	ll cnt=0;
	for(ll i=n;i>1;i--){
		for(ll j=1;j+i-1<=n;j++){
			ll W=a[j+i-1]*i-pre[j+i-1]+pre[j-1];
			if(W<=m){
				cout<<i;
				exit(0);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
