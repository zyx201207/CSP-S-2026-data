#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2e6+5;
int c,t,n,d,x[N],qwq;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		d=d/(x[2]-x[1]);
		d=d+d-1;
		if(d<=1) printf("0\n");
		else{
			int ans=max(qwq,n-d);
			printf("%lld\n",ans);
		}
	}
	return 0;
}

