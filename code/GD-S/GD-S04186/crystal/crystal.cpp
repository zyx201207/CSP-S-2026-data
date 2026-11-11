#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
bool chek(int x){
	long long t=m,mw=a[x];
	int l=1,r;
	for(int i=1;i<x;i++){
		t=t-a[x]+a[r];
	}
	while(r<n && t<0){
		t=t-a[l]+a[r]-(a[r+l]-a[r])*x;
		l++;
		r++;
	}
	return t>=0;
}
int ef(){
	int l=0;
	int r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(a[mid]) l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_stdio(0),cin.tie(0)
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1,chek);
	cout<<ef();
}
