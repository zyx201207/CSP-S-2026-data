#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ans=1;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long z=0,c=1,g=1;
	for(int i=2;i<=n;i++){
		z+=(a[i]-a[i-1])*g;
		g++;
		while(z>m and c<i){
			z-=(a[i]-a[c]);
			c++;
			g--;
		}
		ans=max(ans,g);
	}
	printf("%lld",ans);
	return 0;
}

