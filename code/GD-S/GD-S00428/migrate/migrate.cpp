#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		int ans=0;
		for(int i=1;i<=n;i++){
			int j=upper_bound(x+1+i,x+1+n,x[i]+d)-x-1;
			if(j-i==2)ans++;
		}
		cout<<ans-1<<"\n";
	}
	return 0;
}//Oct31==Dec25?
