#include<iostream>
#include<algorithm>
#define N 500005
using namespace std;
int n;
long long m,a[N];
bool check(int x){
	long long t=m,mw=a[x];
	int l=1,r;
	for(r=1;r<x;r++) t=t-a[x]+a[r];
	while(r<n&&t<0){
		t=t-a[l]+a[r]-(a[r+1]-a[r])*x;
		l++,r++;
	}
	return t>=0;
}
int ef(){
	int l=0,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<ef();
	return 0;
} 
