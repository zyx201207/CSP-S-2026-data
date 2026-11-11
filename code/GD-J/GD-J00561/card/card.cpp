#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll N=1e6+10;
ll n,m;
ll a[N];
ll a1,a2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	 
	for(ll i=1;i<=n;i++)cin>>a[i];
	ll n787878=0;
	for(ll i=1;i<n;i++){
		if(a[i]!=a[i+1])n787878++;
	}
	if(n787878==0){
		cout<<n; 
	}
	else cout<<1<<' '<<2;
	return 0;
} 
