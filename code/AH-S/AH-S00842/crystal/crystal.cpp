#include<bits/stdc++.h>
using namespace std;
int n,ans=-1; long long m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int r=1,l=0; r<=n; r++){
		b[r]=b[r-1]+a[r];
		while(r-l>1&&b[r]-b[l]+m<a[r]*(r-l)) l++;
		ans=max(ans,r-l);
	}
	printf("%lld\n",ans);
	return 0;
}

