#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,ans,a[500050];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int l=1,r=1;l<=n;l++){
		cnt=cnt+a[l];
		while(cnt+m<a[l]*(l-r+1)){
			cnt=cnt-a[r];
			r++;
		}
		ans=max((int)ans,(int)(l-r+1));
	}
	printf("%lld",ans);
	return 0;
}
