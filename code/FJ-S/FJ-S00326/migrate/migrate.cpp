#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n/(d+1)<<endl;
	}
	return 0;
}
