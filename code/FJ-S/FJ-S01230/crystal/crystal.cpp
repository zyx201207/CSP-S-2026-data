#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
typedef long long ll;
ll a[N],pre[N],m;
ll calc(int idx){
	ll x=a[idx];
	int l=0,r=idx;
	while(l+1!=r){
		int mid=(l+r)>>1;
		if(x*(idx-mid)-(pre[idx-1]-pre[mid-1])<=m) r=mid;
		else l=mid;
	}
	return idx-r+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=max(ans,calc(i));
	}
	printf("%lld",ans);
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/