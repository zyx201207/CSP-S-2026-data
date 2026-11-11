#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long 
int x[N],a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		int n,d,ans=0;
		scanf("%d%d",&n,&d);
		vector<int> v(n+10);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n-d;i++){
			for(int j=i+d+1;j<=n;j++){
				if(x[j]-x[i]<2*d and (x[j]-x[i])/2+1<=d and x[j]-x[i]<=2*d-1){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
