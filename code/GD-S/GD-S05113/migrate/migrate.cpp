#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100000086],v[10000086];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		v[i]=v[i-1]+a[i];
	}
	ll maxn=-1;
	for(ll i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(a[mid]*(mid-i+1)-(v[mid]-v[i-1])<=m){
				l=mid+1;
			}else{
				r=mid;
			}
		}
//		cout<<l<<endl;
		if(!(a[l]*(l-i+1)-(v[l]-v[i-1])<=m))l-=1;
		maxn=max(maxn,l-i+1);
//		cout<<i<<" "<<l+1<<endl;
	}
	cout<<maxn;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
