#include<bits/stdc++.h>
using namespace std;
struct kfc{
	long long u,t;
};
struct kfc2{
	kfc e[25];
};
kfc2 a[5000005];
long long c,n,m,d,q,w[500005],ans=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++) scanf("%lld",w[i]);
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%lld%lld",&a[i].e[j].u,&a[i].e[j].t);
		}
	}
	for(int i=0;i<q;i++){
		ans = 0;
		int s,e;
		scanf("%d%d",&s,&e);
		ans += 1LL*w[s-1];
		ans += 1ll*w[e-1];
		printf("%lld",ans+10);
	}
	
	return 0;
} 
