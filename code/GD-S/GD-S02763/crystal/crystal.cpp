#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll a[N],m;
bool chk(int x){
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(i>x) sum-=a[i-x];
		sum+=a[i];
		if(i>=x&&a[i]*(x-1)-(sum-a[i])<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d",l-1);
	return 0;
}
