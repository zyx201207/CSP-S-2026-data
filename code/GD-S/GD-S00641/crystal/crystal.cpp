
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N],ans=-1e9;
bool check(int x){
	int len=x;
	bool fg=0;
	int pos=n+1;
	for (int l=1;l+len-1<=n;l++){
		int r=l+len-1;
		int tot=s[r]-s[l-1];
		if (len*a[r]-tot<=m){
			fg=1;
			break;
		}
	}
	return fg;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=1e18;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
