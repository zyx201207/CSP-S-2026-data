#include <bits/stdc++.h>
using namespace std;
const int N=2000006;
int c,t,n,vis[N];
long long a[N],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			vis[i]=(upper_bound(a+1,a+n+1,a[i]+d)-a)-1;
//			cout << vis[i] << " ";
		}
//		cout << "\n";
		long long ans=0;
		for(int i=1;i<=n;i++){
			int r=vis[i];
			ans+=max(0,vis[r-1]-max(r,vis[r-2]));
		}
		cout << ans << "\n";
	}
	return 0;
}
