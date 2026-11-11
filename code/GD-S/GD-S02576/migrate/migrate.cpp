#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t;
int a[N],n,d,ans,cnt; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int w=2*d;
		for(int i=1;i<=n;i++){
			for(int j=4;j<=n;j++){
				if(a[j]-a[i]>w) break;
				if(a[j]-a[i]>d&&j-i>=3){
					for(int k=i+1;k<=j-1;k++){
						if(a[k]-a[i]<=d&&a[j]-a[k]<=d)
						cnt++;
					}
					if(cnt==2) ans++;
					cnt=0;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
