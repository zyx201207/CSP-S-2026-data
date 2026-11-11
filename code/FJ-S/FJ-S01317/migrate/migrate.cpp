#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+5;
ll c,t,n,d,x[N];
bool can(int k){
	bool f=false,ff=false;
	for (int i = 1;i<k;i++){
		if (x[i]+d-1==x[k]){
		    f=true;
			break;
		}
		if (x[i]>x[k]-d+1)
			break;
	}
	for (int i = k+2;i<=n;i++){
		if (x[k]+d==x[i]){
			ff=true;
			break;
		}
		if (x[i]>x[k]+d)
			break;
	}
	if (f && ff)
	    return true;
	return false;
}
void work(){
	ll cnt = 0;
	scanf("%lld%lld",&n,&d);
	for (int i = 1;i<=n;i++)
		scanf("%lld",&x[i]);
	for (int i = 2;i<n-1;i++)
		if (x[i]+1==x[i+1])
			if (can(i))
			    cnt++;
	printf("%lld\n",cnt);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while (t--){
		work();
	}
	return 0;
}

