#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[200005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>x[j];
		cout<<(n-2)*(n-3)<<"\n";
	}
	return 0;
}
