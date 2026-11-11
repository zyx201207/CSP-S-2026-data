#include<bits/stdc++.h>
#define MAXN 200005
#define ll long long 
using namespace std;
ll minx(ll a,ll b){
	return a>b?b:a;
}
ll a[MAXN];
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld %c",&a[i],&c[i]);
	int l=1,r=n;
	ll cntl=a[l],cntr=a[r];
	ll ans=0;
	while(1){
		if(c[l]!=c[r])ans+=minx(cntl,cntr);
		if(cntl<cntr&&l<r-1)cntr-=cntl,cntl=a[++l];
		else if(cntl>cntr&&l<r-1)cntl-=cntr,cntr=a[--r];
		else if(cntl==cntr&&l<r-2)cntl=a[++l],cntr=a[--r];
		else break;
	}
	printf("%lld",ans);
	return 0;
} 
