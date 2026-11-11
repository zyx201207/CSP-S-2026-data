#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,maxn=-1,a[400000];
void f(ll cnt,ll x,ll k){
	if(cnt==m){
		maxn=max(maxn,x);
		return ;
	}
	if(k==n) return ;
	f(cnt+1,x&a[k+1],k+1);
	f(cnt,x,k+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		f(1,a[i],i);
	}
	cout<<maxn;
}
