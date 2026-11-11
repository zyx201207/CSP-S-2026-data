//GZ-S00023 贵阳市白云区华师一学校 吴星汉 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	mt19937 rng(time(0));
	uniform_int_distribution<ll> dist(1,1000);
	cin>>c>>t;
	while(t--) printf("%lld\n",dist(rng));
	return 0;
}
