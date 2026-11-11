#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans,d[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int zxs=0;
		for(int i=1;i<=n;i++){
			ans=a[1];
			if(i==1) ans=a[2];
			for(int j=1;j<=n;j++){
				if(i!=j) {
					ans=max(ans,ans&a[j]);
				}
			}
			zxs=max(zxs,ans);
		}
		cout<<zxs;
		return 0;
	}
	cout<<a[n];
	return 0;
}
