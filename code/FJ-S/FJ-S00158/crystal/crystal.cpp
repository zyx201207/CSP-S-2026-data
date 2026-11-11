#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid l+(r-l)/2
int n,m,a[500005],b[500005],l,r;
bool ans[500005],now;
bool fun(int x,int y){
	int now=b[y]*x-a[y]+a[y-x-1];
	if(now<0||now>m) return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) a[i]=a[i-1]+b[i];
	l=1,r=n;
	while(l<r){
		now=0;
		for(int j=mid;j<=n;j++){
			if(fun(mid,j)){
				now=1;
				break;
			}
		}
		if(now==1) l=mid;
		else r=mid-1;
	}
	printf("%lld\n",l);
	return 0;
}
