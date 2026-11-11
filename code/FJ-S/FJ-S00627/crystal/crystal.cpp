#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 500005
#define ll long long
#define INF (ll)1e18
#define PII pair<ll, ll>
#define lowbit(x) (x&(-x))

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=0; ch=getchar(); }
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return (f?res:-res);
}
ll n, m, a[N], sum[N], res;
bool check(ll x, ll y){
	return (a[y]*(y-x+1)-(sum[y]-sum[x-1]))<=m; 
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n=rd(), m=rd();
	for(int i=1; i<=n; i++) a[i]=rd();
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	for(int R=1; R<=n; R++){
		ll l=1, r=R, ans=R;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid, R)) ans=mid, r=mid-1;
			else l=mid+1;
		}
//		cout<<R<<' '<<ans<<endl;
		res=max(res, R-ans+1);
	}
	printf("%lld\n", res);
	
	return 0;
}
/*

*/
