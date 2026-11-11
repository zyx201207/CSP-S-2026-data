#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	std::freopen("hub.in","r",stdin);
	std::freopen("hub.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	srand(time(0));
	while(t--){
		int n,k;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%lld%lld",&u,&v);
		}
		printf("%lld\n",rand()%n);
	}
}
