#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxN=5e5;
int n,ans;
ll m,a[maxN+5],s[maxN+5];
void solve(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int r=1;r<=n;r++){
		int l=r;
		for(int pw=(1<<18);pw;pw/=2){
			int l_=l-pw;
			if(1<=l_&&(r-l_+1)*a[r]-(s[r]-s[l_-1])<=m)
				l=l_;
		}
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	for(;T;T--) solve();
}

