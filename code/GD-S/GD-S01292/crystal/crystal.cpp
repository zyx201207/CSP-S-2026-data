#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define N 500005
#define LL long long

using namespace std;

LL n,m,a[N],sum[N],maxans[N],mx[N],pj,k;

bool check(int len){
	bool f=false;
	for(int i=1;i+len-1<=n;i++){
		int l=i,r=i+len-1;
		pj=(sum[r]-sum[l-1]+m)/len;
		if(a[r]<=pj) return true;
	}
	return false;
}
int find(){
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return l;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) maxans[i]=max(maxans[i-1],a[i]);

	cout<<find();
	return 0;
}
