#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e6+5;
LL c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(LL i=1;i<=n;i++) cin>>x[i];
		LL k=d/(x[2]-x[1]);
		cout<<n-k<<"\n";
	}
	return 0;
}
