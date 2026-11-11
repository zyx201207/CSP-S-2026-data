//
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;

int a[MAXN],pre[MAXN];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	
	int l=1,ans=0;
	for (int i=1;i<=n;i++){
		while (a[i]*(i-l+1)-pre[i]+pre[l-1]>m) l++;
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);

	return 0;
}

