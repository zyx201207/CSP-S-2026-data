#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005];
int ans=0;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int id=1,num=1;
	for(int i=2;i<=n;++i){
		num = i-id;
		while(id <= i-1 and num*(a[i]-a[i-1]) > m){
			m = m+a[i-1]-a[id];
			id++;
			num--; 
		}
		m -= num*(a[i]-a[i-1]);
		ans = max(ans,i-id+1);
	}
	printf("%lld",ans);
	return 0;
}
