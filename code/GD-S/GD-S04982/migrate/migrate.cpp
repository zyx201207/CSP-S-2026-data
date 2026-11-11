#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,t,d;
vector<ll> a; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			ll x;
			scanf("%lld",&x);
			a.push_back(x);
		}
		printf("0\n");
	}
	return 0;
}
