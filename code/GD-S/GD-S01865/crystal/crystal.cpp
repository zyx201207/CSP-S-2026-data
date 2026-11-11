#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],i=0,ans=1,mk,maxx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	mk=m; ans=1;
	for(int i=1;i<n;i++){
		mk-=ans*(a[i+1]-a[i]);
		ans++;
		if(mk<0){
			ans--;
			maxx=max(maxx,ans);
			ans=1;
			mk=m;
		}
	}
	maxx=max(maxx,ans);
	printf("%lld",maxx);
	return 0;
}
