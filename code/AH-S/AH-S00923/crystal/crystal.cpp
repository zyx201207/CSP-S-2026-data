#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
ll n,m,a[N];
ll s[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(ll len=1;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			ll l=i,r=i+len-1;
			ll sum=s[r]-s[l]+a[l];
			ll totalsum=a[r]*len;
			ll cha=totalsum-sum;
			if(cha<=m)ans=max(ans,len);
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
