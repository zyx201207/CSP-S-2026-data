#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		int p=min(a[l],a[r]);
		a[l]-=p;a[r]-=p;
		if(c[l]!=c[r])ans+=p;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	printf("%lld\n",ans);
	return 0;
}
