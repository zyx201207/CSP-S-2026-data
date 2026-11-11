#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
ll ans=0;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d %c",&a[i],&c[i]);
	}
	int l=1,r=n;
	while(l<=r){
		int mi=min(a[l],a[r]); 
		if(c[l]!=c[r])ans+=mi;
		if(a[l]==a[r])l++,r--;
		else if(a[l]==mi)l++,a[r]-=mi;
		else r--,a[l]-=mi;
	}
	printf("%lld",ans);
	return 0;
}
