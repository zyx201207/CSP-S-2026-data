#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
using namespace std;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans=0;
	int curl=1;
	int tot=0;
	for(int i=1;i<=n;++i){
		tot+=(i-curl)*(a[i]-a[i-1]);
		while(curl+1<=i&&tot>m){
			tot-=a[i]-a[curl];
			++curl;
		}
		ans=max(ans,i-curl+1);
	}
	cout<<ans;
	return 0;
}
