#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
const int INF=0x3f3f3f3f;
int n,m,a[N],b[N],c[N],id=1,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[ans]+=(a[i]-a[i-1])*ans-(a[i]-a[i-ans]);
		for(int j=ans+1;j<=i;j++){
			if(b[j-1]<=m){
				ans=j-1;
			}else{
				break;
			}
			b[j]=b[j-1]+(a[i]-a[i-j+1]);
			if(b[j]<=m){
				ans=j;
			}else{
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
