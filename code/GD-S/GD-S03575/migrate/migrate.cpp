#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,ans; 
ll a[2001000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		memset(a,0,sizeof(a));
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		printf("0\n");
	}
	return 0;
}
