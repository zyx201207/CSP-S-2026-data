#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
long long d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		long long x=1e18+10;
		long long ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=2;i<=n;i++){
			x=min(x,a[i]-a[i-1]);
		}
		long long cnt=d/x;
		for(int i=2;i<=cnt;i++){
			for(int j=1;j<=n;j+=i*x+1){
				ans++;
			}
		}
		if(d<x*2) printf("0\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
