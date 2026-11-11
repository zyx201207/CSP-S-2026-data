#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll C,T;
ll n,d;
ll dm[2000001];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","W",stdout);
	cin>>C>>T;
	for(int qwerty=1; qwerty<=T; qwerty++) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>dm[i];
		}
		ll kl=0;
		for(int i=2; i*d<=n; i++) {
			kl+=n-i*d+1;
		}
		cout<<kl<<endl;
	}

	return 0;
}
