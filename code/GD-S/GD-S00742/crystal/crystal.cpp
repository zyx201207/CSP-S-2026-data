#include<bits/stdc++.h>
using namespace std;typedef long long ll;
const int N=5e5+5;const ll ab=1e12+1;
int i,j,mi,h,n,t=1,g,l,r,as=1;
ll m,a[N],x,s[N],k;
bool ok(){
	k=s[h-1]-s[mi-1];
	k=1ll*a[h]*(h-mi)-k;
	if(k<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&x);
		a[i]=x+ab;
	}sort(a+1,a+i);
	for(i=1;i<=n;i++){
		a[i]-=ab;
		s[i]+=s[i-1]+a[i];
	}
	while(t<=n){
		h=t;
		t=upper_bound(a+1,a+n+1,a[h])-a;
		g=t-h;
		l=1,r=h-1;
		while(l<r){
			mi=l+r>>1;
			if(ok()){
				r=mi;
			}else{
				l=mi+1;
			}
		}
		as=max(as,h-r+g);
	}
	printf("%d",as);
	return 0;
}
