#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,l,r,ans=1,mid;
ll m,t,an[500005],a[500005];
ll w(int l,int r){
	return a[r]*(r-l+1)-(an[r]-an[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)an[i]=an[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=1,r=i-1;
		int p=i;
		while(l<=r){
			int md=l+r>>1;
			if(w(md,i)<=m)p=md,r=md-1;
			else l=md+1;
		}
		ans=max(ans,i-p+1);
	}
	printf("%d",ans);
	return 0;
}
