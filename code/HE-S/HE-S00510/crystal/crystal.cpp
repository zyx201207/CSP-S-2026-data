#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll s[500005]; 
ll d=0;
ll w=0;
ll o=1;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		}
		sort(a+1,a+n+1);
for(ll i=1;i<=n;i++){
	ll k=a[i];
	d+=(a[i+1]-k)*i;
	s[o]++;
	if(d<0-m){
	s[o]--;
	break;
	}
	else if(d>m){
	o+=i-1;
	s[o]=0;
	d=0;
	continue;
	}
}
sort(s+1,s+n+1,cmp);
cout<<s[1];
	return 0;
}
