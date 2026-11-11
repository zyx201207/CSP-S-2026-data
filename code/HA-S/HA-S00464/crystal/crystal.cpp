#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

const int N=500005;

int n;
ll m;
ll a[N],sum[N];
bool chk(int mid){
	for(int i=1;i+mid-1<=n;i++){
		int l=i,r=i+mid-1;
		ll val=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
		if(val<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(chk(mid))l=mid;
		else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
