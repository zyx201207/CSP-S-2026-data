#include <bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n=read(),m=read();
	int a[500010]={};
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)printf("%lld%c",a[i]," \n"[i==n]);
	int r=n,l=n,co=0,ans=1;
	for(;r>=1;r--){
		while(l>1&&co+a[r]-a[l-1]<=m){
			co+=a[r]-a[l-1];l--;
		}
		ans=max(ans,r-l+1);
		co-=(a[r]-a[r-1])*(r-l);
	}
	printf("%lld",ans);

	return 0;
}

