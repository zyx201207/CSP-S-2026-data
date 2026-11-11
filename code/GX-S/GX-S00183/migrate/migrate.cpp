#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6+5;
ll c,t;
ll n,d;
ll nbdis[N];
ll llabs(ll num){
	if(num >= 0)return num;
	else return (num * -1);
}
int main(){
	scanf("%lld %lld",&c,&t);
	cin>>c>>t;
	while(t--){
		ll x[N];
		scanf("%lld %lld",&n,&d);
		for(int i = 1;i<=n;i++){
			scanf("%lld",&x[i]);
			if(i >= 2 && (x[i] - x[i-1]) <= d)nbdis[i] = x[i] - x[i-1];
		}
		
	}
	return 0;	
}
