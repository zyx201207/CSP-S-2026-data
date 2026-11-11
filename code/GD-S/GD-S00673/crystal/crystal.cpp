#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],pre[N];
ll c[N],ans=1,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	pre[1]=0;
	for(ll i = 2;i<=n;i++) pre[i]=a[i]-a[i-1];
	ll l = 1,r=2;
	bool b=1;
	while(l<n){
		if(b) sum=sum+pre[r]*(r-l);
		if(sum<=m){
			ans=max(r-l+1,ans);
//			printf("1 %lld %lld %lld %lld\n",l,r,sum,ans);
			r++;
			b=1;
		}
		else{
//			printf("0 %lld %lld %lld\n",l,r,sum);
			sum-=a[r]-a[l];
			l++;
			b=0;
		}
		if(r==n) break;
	}
	printf("%lld",ans);
	return 0;
}
