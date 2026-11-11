#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
ll n,d;
ll x[100086];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll i=0;i<t;i++){
		cin>>n>>d;
		for(ll j=0;j<n;j++){
			cin>>x[j];
		}
		printf("%lld\n",n/4);
	}
	return 0;
}
