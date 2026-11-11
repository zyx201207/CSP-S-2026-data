#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,t,d,q,a;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n+1;i++)cin>>a;
		cout<<(n+1)/3<<'\n';
	}
	return 0;
}
