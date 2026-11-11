#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[500005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<(n%2 ? n/2+1 : n/2-1)<<'\n';
	}
	return 0;
}
