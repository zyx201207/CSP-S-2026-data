#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m,a[N],pre[N];
ll ans;
bool check(ll x){
	for(int i=x;i<=n;i++)
		if(a[i]*x-(pre[i]-pre[i-x])<=m) return true;
	return false;
}
ll bs(ll l,ll r){
	while(l<r){
		ll mid=l+((r-l+1)>>1);
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}
void Solve()
{
	cin>>n>>m;
	pre[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	ans=bs(1,n);
	cout<<ans<<"\n";
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}
