#include<bits/stdc++.h>
#define int long long 
using namespace std;

int n,m,ans=1;
int a[500010];
int t[500010];

signed main( ){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		t[i]=t[i-1]+a[i];
	}
	int j=n-1;
	for(int i=n;i>=1;i--){
		while(t[i-1]-t[j-1]+m>=(i-j)*a[i]&&j>=1) j--;
		if(j<i) j++;
//		cout<<i<<" "<<j<<endl;
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}
