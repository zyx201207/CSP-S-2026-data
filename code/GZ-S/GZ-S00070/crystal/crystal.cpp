// GZ-S00070 贵阳市白云区华师一学校 王舒越 
#include<bits/stdc++.h>
#define ll long long
#define MAXN 500010
using namespace std;
ll n,m,ans,a[MAXN],s[MAXN];
bool check(ll x){
	ll minn=0,cnt=0,num=0,w=0;
	for(ll i=1;i<=x;i++) w++,minn+=(s[i]*w),num+=s[i];
	cnt=minn;
	for(ll i=2;i<=n-x;i++){
		cnt+=(s[i+x-1]*w),cnt-=num;
		if(cnt<minn) minn=cnt;
		num-=s[i-1],num+=s[i+x-1];
	}
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++) s[i-1]=a[i]-a[i-1];
	ll l=1,r=n;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid-1)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
