#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MXN=5e5+5;
int n,l,r;
ll m,a[MXN],pfs[MXN];
bool check(int k){
	for(int i=k;i<=n;i++){
		if(a[i]*k-(pfs[i]-pfs[i-k-1])<=m)return true;
	}
	return false;
}
int main(){
	// 14:37 100pts
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pfs[i]=pfs[i-1]+a[i];
	l=1;r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1; 
	}
	cout<<l;
}
