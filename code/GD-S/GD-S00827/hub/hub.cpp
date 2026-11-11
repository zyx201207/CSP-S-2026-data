#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
void solve(){
	scanf("%lld%lld",&n,&k);
	for(int i=2;i<=n;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
	}
	printf("%lld\n",k-1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%lld%lld",&c,&T);
	while(T--) solve();
}
