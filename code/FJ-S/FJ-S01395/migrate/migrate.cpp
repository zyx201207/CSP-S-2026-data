#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("imgrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int tt=1;tt<=t;tt++){
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		long long sx=x[2]-x[1];
		long long d2=d/sx;
		int ans=0;
		for(int i=1;i*d2<=n;i++){
			ans+=n-i*d2;
		}
		printf("%d\n",ans);
	} 
}

