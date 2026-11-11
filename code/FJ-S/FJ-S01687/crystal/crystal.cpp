#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,m,c,ans=1,a[N];
ll dfs(ll t){
	int q=m,res=1;
	for(ll i=t+1;i<=n;i++){
		ll x=(a[i]-a[i-1])*(i-t);
		if(q>=x) q-=x,res++;
		else return res;
	}
	return res;
}
ll num(ll k){
	ll res=1;
	for(ll i=1;k>=(i*c);i++){
		k-=(i*c);res++;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;bool p=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(p && i>1){
			if(i==2) c=a[2]-a[1];
			else if(i>2){
				if(a[i]-a[i-1]!=c) p=0;
			}
		}
	}
	if(p){cout<<num(m);return 0;}
	sort(a+1,a+n+1);
	for(ll i=1;i<n;i++){
		ans=max(ans,dfs(i));
	}
	cout<<ans;
	return 0;
} 
