#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
int n,m,a[500005],pre[500005];
bool check(int cnt){
	int mn=9e18;
	rep(i,cnt,n){
		int st=i-cnt+1,ed=i;
		int sum=pre[ed]-pre[st-1];
		int req=a[i]*cnt-sum;
		mn=min(mn,req);
	}
	return mn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) pre[i]=pre[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
// luogu uid: 682739
// I love ShootingStar (luogu uid: 748859) forever!
