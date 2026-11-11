#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int a[N],cnt[N];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++){
		cnt[i]=cnt[i-1]+a[i];
	}
	int ans=0,l=1,r=1;
	while(r<=n){
//		cout << l << ' ' << r << '\n';
		if(cnt[r]-cnt[l-1]+m>=(r-l+1)*a[r])ans = max(ans,r-l+1),++r;
		else ++l;
	}
	cout << ans;
	return 0;
} 


