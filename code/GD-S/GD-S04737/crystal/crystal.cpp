#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],z[500005],k=1,cnt=1,t,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		z[i]=a[i]-a[i-1];
		z[i]=z[i]+z[i-1];
	}
	for(int i=2;i<=n;i++){
		cnt=cnt+1;
		t=t+(z[i]-z[i-1])*(cnt-1);
		while(t>m){
			t=t-(z[i]-z[k]);
			k++,cnt--;
		}
		if(ans<cnt) ans=cnt;
	}
	printf("%lld",ans);
	return 0;
}
