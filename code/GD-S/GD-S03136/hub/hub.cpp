#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+86;
ll n,t,m,c;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		ll x=rand()%n;
		printf("%lld\n",x);
	}
	return 0;
}

