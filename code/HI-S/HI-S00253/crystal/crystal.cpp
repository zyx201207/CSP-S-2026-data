#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,t;
int n,ans=1,l=1,r=2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	while(r<=n){
		t+=(r-l)*(a[r]-a[r-1]);
		while(t>m){
			t-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	printf("%d",ans);
	return 0;
}
