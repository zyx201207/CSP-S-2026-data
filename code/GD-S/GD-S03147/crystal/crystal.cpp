#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],c[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) c[i]=a[i+1]-a[i];
	s[1]=c[1];
	int ans=-1e18;
	bool f=0; 
	for(int i=2;i<n;i++) s[i]=i*c[i]+s[i-1];
	if(n<=1000){
		for(int i=1;i<n;i++){
			if(s[i]<=m) {
				ans=max(ans,i+1);
				continue;
			}
			int sum=0;
			for(int j=1;j<i;j++){
				sum+=a[i+1]-a[j];
				if(s[i]-sum<=m){
					ans=max(ans,i+1-j);
					f=1;
				}
			}
		}	
		if(f) printf("%lld",ans);
		else puts("0");
		return 0;
	}

	for(int i=1;i<n;i++) {
		if(s[i]<=m) {
			ans=max(ans,s[i+1]);
			f=1;
		}
	}
	for(int i=n-1;i>=1;i--) {
		if(s[i]==ans) {
			cout<<i;
			return 0;
		}
	}
	if(f)printf("%lld",ans);
	else puts("0");
	return 0;
} 
