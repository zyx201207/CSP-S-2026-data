#include<bits/stdc++.h>
using namespace std;

#define sht short
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define xwy114514 ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int INTINF=0x7f7f7f7f;
const ll LONGINF=0x3f3f3f3f3f3f3f3f;

const ll N=5e5+10;

ll n,m,a[N],c[N],ans=0ll,add=0ll;

void solve(ll id){
	ll l=0ll,r=id,res=0ll;
	while(l<=r){
		ll mid=(l+r)/2ll;
		if(a[id]*mid-(c[id]-c[id-mid])<=m)l=mid+1ll,res=mid;
		else r=mid-1ll;
	}
	ans=max(ans,res);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	xwy114514;
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)c[i]=c[i-1]+a[i];
	for(ll i=1;i<=n;i++)solve(i);
	cout<<ans<<endl;
	
	return 0;
}
/*
发现n很小，考虑从n下手，每个值二分一下最多几个
check一次是多少？哦 那就是这样吧，维护前后的到某个点的代价
不是我是** 我发现只能增加1.。。那不就好办了 直接往前面二分就好了
5 5
1 2 4 8 9 
气死我了耗我这么久。。。 
5 8
-3 -1 2 2 7
*/
