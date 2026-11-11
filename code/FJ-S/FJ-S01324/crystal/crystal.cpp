#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,l,r,mid;
long long a[N],m;
bool check(){
	for(int i=1;i<=n-mid;i++){
		long long cost=0;
		for(int j=1;j<=mid;j++){
			cost+=(a[i+j])*j;
			if(cost>m) break;
		}
		if(cost<=m) return 1;
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
	for(int i=n;i>=2;i--) a[i]-=a[i-1];
	r=n;
	while(l<r){
		mid=(l+r)>>1;
		printf("l=%d,r=%d,mid=%d\n",l,r,mid);
		if(check()) l=mid+1;
		else r=mid;
	}
	printf("%d",l);
	return 0;
}
