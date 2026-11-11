#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sug=5e5+5;
int c,t,n,d;
int x[sug];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=0;i<n;i++) cout<<i<<"\n";
	}
	return 0;
}
//c__c__f
