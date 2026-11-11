#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n;
ll m,a[N],s[N],f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	s[1]=0;
	for(int i=2;i<=n;i++) s[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++) f[i]=f[i-1]+s[i];
	int ans=1;ll sum=0;
	for(int r=1,l=1;r<=n;r++){
		sum+=(r-l)*s[r];
		while(l<r&&sum>m) sum-=f[r]-f[l],l++;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	
	return 0;
}
