#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005;
int c,t,n,d;
int x[N],f[N][2];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			if(x[i]+2*d>x[n])continue;
			int w=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			int l=upper_bound(x+1,x+n+1,x[w-2]+d+1)-x-1;
			int r=upper_bound(x+1,x+n+1,x[w-1]+d)-x-1;
			ans+=r-l+1;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
