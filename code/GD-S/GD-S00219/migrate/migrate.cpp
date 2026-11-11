#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			ll k;
			cin>>k;
			x[i]=k;
		}
		if(c>=11&&c<=12){
			if((x[2]-x[1])*2<=d&&d<x[n]-x[1]){
				cout<<n-(d/(x[2]-x[1])*2-1)<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}

