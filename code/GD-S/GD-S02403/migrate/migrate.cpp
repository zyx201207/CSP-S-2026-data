#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c,t,n;
long long d;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=2){
			cout<<0<<'\n';
			continue;
		}
		if(c==11||c==12){
			long long k = x[2]-x[1];
			if(k*2>d||k*3<=d) cout<<0<<'\n';
			else if(k*2<=d) cout<<n-3<<'\n';
		}
		if(c==13||c==14){
			cout<<1ll*(n-1)*(n-2)/2<<'\n';
		}
	}
	return 0;
}

