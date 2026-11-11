#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		int n,k;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%lld%lld",&x,&y);
		}
		int ans=(k+1)/2;
		printf("%lld\n",ans);
	}
} 
