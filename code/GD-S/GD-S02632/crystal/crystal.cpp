#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ans,res,rem,id,k;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld\n",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld ",&a[i]);
	}
	sort(a+1,a+n+1);
	id=k=n;
	rem=m;
	res=1;
	while(id>1&&rem>=a[k]-a[id-1]){
		id--;
		res++;
		rem-=a[k]-a[id];
	}
	ans=max(ans,res);
	while(id>1){
		k--;
		res--;
		if(a[k]==a[k+1]) continue;
		rem+=res*(a[k+1]-a[k]);
		while(id>1&&rem>=a[k]-a[id-1]){
			id--;
			res++;
			rem-=a[k]-a[id];
		}
		ans=max(ans,res);
	}
	printf("%lld",ans);
	return 0; 
} 
