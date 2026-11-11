#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int a[2000005],f[2000005],g[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		f[1]=1;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			g[i]=1;
			if(i==1) continue;
			if(a[1]+d>=a[i]){
				f[i]=1;
				continue;
			}
			int x=lower_bound(a+1,a+i+1,a[i]-d)-a;
			f[i]=f[x]+1;
			g[i]+=g[x];
		}
		int ans=0;
		for(int i=3;i<n;i++){
			int x=lower_bound(a+1,a+n+1,a[i-1]+d)-a,y=lower_bound(a+1,a+n+1,a[i]-d)-a;
			if(a[x]==a[i-1]+d){
				if(a[i+1]-d>a[y]&&a[i-2]+d<a[x]&&f[i]==f[i-1]){
					ans+=g[y];
				}
			}else{
				if(a[i+1]-d>a[y]&&a[i-2]+d<a[x-1]&&f[i]==f[i-1]){
					ans+=g[y];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
