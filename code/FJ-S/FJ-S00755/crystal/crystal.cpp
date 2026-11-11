//crystal.cpp
#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n,m,a[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	LL t=m,anst=ans,p=n;
	for(LL i=n;i>1;i--){
		anst--,t+=anst*(a[i+1]-a[i]);
		for(LL j=p;j>=1;j--){
			if(t-(a[i]-a[j])<0){
				p=j;
				break;
			}
			anst++,t-=a[i]-a[j];
			if(j==1) p=0;
		}
		ans=max(ans,anst);
	}
	printf("%lld",ans);
	return 0;
}
