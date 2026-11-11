#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],b[N],ans=0;
bool ck(ll x,ll y){
	return (y-x+1)*a[y]-b[y]+b[x-1]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,res=i;
		while(l<=r){
			ll md=(l+r)>>1;
			if(ck(md,i)) r=md-1,res=md;
			else l=md+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<endl;
}
/*
最终的 x 一定是某个 a[i]
否则一定没有取某个 a[i] 更好
假设 x=a[i]
对于 i，算 b[i]=abs(a[i]-x)
\sum b[i]<=m
只能选 a[j]<=a[i] 的
二分要选几个，肯定是从 i 开始的一段后缀
设二分到 p
p*a[i]-a[i-p]~a[i] <= m
O(n\logn) 
*/
