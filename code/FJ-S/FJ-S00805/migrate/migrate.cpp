#include <bits/stdc++.h>//8
using namespace std;
typedef  unsigned long long ull;
const int N=2e6+10;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		memset(x,0,sizeof(x));
		ull n,d;cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		ull d0=x[n]-x[n-1];
		if(2*d0>d)cout<<0<<'\n';
		else {
			ull p=d/d0;if(n>=p*2)cout<<n-p*2+1<<'\n';
			else cout<<0<<'\n';
		}
	}
	return 0;
}
