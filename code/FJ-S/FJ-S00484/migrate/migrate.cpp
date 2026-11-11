#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,t,n,d,q,x[2000005],ans=1;
signed main(){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		cin>>n>>d;
		for (int j=1;j<=n;j++)cin>>x[j];
		q=n-3;
		while (q>0){
			ans*=q;
			q--;
		}
		cout<<ans<<endl;
		ans=1;
	}
	return 0;
}
