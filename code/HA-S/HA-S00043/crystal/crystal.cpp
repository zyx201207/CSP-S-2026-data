#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull n,m,a[500005],ans,d;
bool check(ull x){
	ull cnt=(a[0]+a[x])*x/2;
	if(cnt>d) return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ull gc=a[1]-a[0];
	d=m/gc;
	ull l=0,r=n+1;
	while(l<r){
		ull mid=l+(r-l)/2;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<l;
	return 0;
}

