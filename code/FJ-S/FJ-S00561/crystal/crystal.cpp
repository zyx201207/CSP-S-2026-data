#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll sum=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m) break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
