#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,L=LONG_LONG_MAX,R=LONG_LONG_MIN;
int f(int x){
	int k=0;
	for(int i=1;i<=n;i++){
		if(a[i]<x) k+=x-a[i];
		if(k>m) return m+1;
	}
	return k;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		L=min(L,a[i]);
		R=max(R,a[i]);
	}
	sort(a+1,a+n+1);
	long long mid,ans=0;
	while(L<=R){
		mid=(L+R)/2;
		int k=f(mid);
		if(L==mid){
			break;
		}
		if(k<m){
			L=mid;
		}else if(k>m){
			R=mid;
		}else{
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=mid) ans++;
	}
	cout<<ans; 
	return 0;
}
