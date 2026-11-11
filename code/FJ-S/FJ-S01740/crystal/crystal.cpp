#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
using namespace std;
const int N=500099;
int n;
ll m;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	FOR(i,1,n){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	FOR(i,1,n){
		sum[i]=1ll*(ll)sum[i-1]+a[i];
	}
	int l=0,ma=0;
	FOR(i,1,n){
		while(1ll*(ll)(1ll*a[i]*(i-l)-(sum[i]-sum[l]))>m)++l;
		ma=max(ma,i-l);
	}
	printf("%d\n",ma);
	return 0;
}
