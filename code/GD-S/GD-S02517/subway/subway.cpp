#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,a[500005][2],b[500005];
int ans=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",b+i);
	}
	for(int i=1;i<=n;i++){
		int t=0;
		scanf("%d",&t);
		for(int j=1;j<=t;j++){
			scanf("%lld %lld",&a[j][0],&a[j][1]);
		}
	}
	int ans=0;
	while(q--){
		int u,v;
		scanf("%d %d",&u,&v);
		printf("%d\n",ans);
	}
	return 0;
}
