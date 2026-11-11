#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+1;
ll n,m,s,a[N];
bool f(ll i,ll d){
	return (a[d]-a[d-1])*(d-i+1)-(a[d]-a[i-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	for(int i=1;i<=n;i++){
		ll l=i,r=n;
		while(l<r){
			int d=l+r+1>>1;
			if(f(i,d)) l=d;
			else r=d-1;
		}
		s=max(s,l-i+1);
	}
	cout<<s;
	return 0;
}
