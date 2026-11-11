#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+3;
int n,m,ans;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for(int i=1; i<=n; i++)scanf("%lld", &a[i]);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)s[i]=s[i-1]+a[i];
	for(int i=n; i>0; i--){
		int l=1,r=i;
		while(l<r){
			int k=l+r>>1;
			if(a[i]*(i-k)-(s[i-1]-s[k-1])<=m)r=k;
			else l=k+1;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld", ans);
	return 0;
}
