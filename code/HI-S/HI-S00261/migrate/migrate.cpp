#include<bits/stdc++.h>
#define ll long long
#define l int
using namespace std;
l MAX_L=214748347;
ll c,t;
ll a[2000010];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>c>>t;
	for(ll k=1;k<=t;k++){
		ll n,d;
		scanf("%lld %lld",&n,&d);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
	}
	return 0;
}

