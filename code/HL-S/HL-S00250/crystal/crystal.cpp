#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll b[500005];
int solve(ll s){
	ll num=0;
	int r1;
	for(int i=s;i<n;i++){
	 	num+=b[i]*i;
	    if(num>m){
			r1=i;
    		break;
	 	}	
	}
	return r1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,less<int>());
	b[0]=a[0];
	for(ll i=1;i<n;i++){
		b[i]=a[i]-a[i-1];
	}
	int maxn=-1e9;
	for(ll i=1;i<n;i++){
		maxn=max(maxn,solve(i));
	}
	cout<<maxn;
	return 0;
}
