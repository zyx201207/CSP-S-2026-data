#include <bits/stdc++.h>//应该能AC???
using namespace std;
#define int long long
int n,m,a[500010],sum[500010],l,r;
bool check(int x){
	int pos=upper_bound(a+1,a+n+1,x)-a;
	if(pos==1) return 1;//所有水晶都在x之上
	else if(a[pos]<=x||pos>n) pos=n;//都在x以下
	else pos--;
	return ((x*pos-sum[pos])<=m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	l=a[1];
	r=a[n];
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}//此时r就是最终能量值
	int ans,pos=upper_bound(a+1,a+n+1,r)-a;
	if(pos==1) ans=0;//所有水晶都在r之上
	else if(a[pos]<=r||pos>n) ans=n;//都在r以下
	else ans=pos-1;
	printf("%lld",ans);
	return 0;
}