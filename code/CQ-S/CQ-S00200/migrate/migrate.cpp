#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace lp{
	int x,t,n,d,a[5005],pr,f[5005],f2[5005],s[5005],ans;
	signed main(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>x>>t;
		while(t--){
			cin>>n>>d,ans=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++){
				f[i]=0,f2[i]=s[i]=1,s[i-1]=0;
				for(int j=i+1;j<=n;j++){
					pr=lower_bound(a+i,a+j,a[j]-d)-a;
					if(pr!=j)f[j]=f[pr]+1,f2[j]=s[upper_bound(f+pr,f+j,f[pr])-f-1]-s[pr-1],s[j]=s[j-1]+f2[j];
					if(f2[j]==2)ans++;
					if(f2[j]>2)f2[j]=3;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
}
signed main(){
	lp::main();
	return 0;
}

