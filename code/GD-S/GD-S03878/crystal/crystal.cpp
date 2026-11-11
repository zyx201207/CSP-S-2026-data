#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+2;
int n,ans;
ll m,a[N],p[N];
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=2;i<=n;++i) p[i]=p[i-1]+a[i]-a[i-1];
	int l=1,r=2;
	while(l<r && r<n){
		while(p[r]-p[l]<m && r<n) ++r;
		if(p[r]-p[l]>m) --r;
		ans=max(ans,r-l+1),++l;
	}
	printf("%lld",ans);
	fclose(stdin),fclose(stdout);
	return 0;
}
