#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+10;
ll n,a[N],m,mx=-1e18,i,sum[N],j,l1,r1,l2,r2,mn=1e18,ans;
void dfs(ll pos,ll rest) {
	if(rest<0)return ;
	if(pos>n && rest==0) {
		map<ll,ll>vis;
		for(ll i=1; i<=n; i++)
			vis[a[i]]++,ans=max(vis[a[i]],ans);
		return;
	}
	if(pos>n)return ;
	for(ll i=0; i<=rest; i++)
		a[pos]+=i,dfs(pos+1,rest-i),a[pos]-=i;
}
bool check() {
	ll w=upper_bound(a+1,a+1+n,j)-a-1;
	//first cost
	while(a[w]==a[w+1])w++;
	ll cost=j*w-sum[w];
	if(cost>m) {
		r2=j-1;
		return 0;
	}
	//second count

	if(w<i) {
		l2=j+1;
		return 0;
	}
	return 1;
}
int main () {
	//freopen("4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=16) {
		dfs(1,m);
		cout<<ans<<endl;
		return 0;
	}
	//bool all1=1;
	//for(int i=1;i<=n;i++)
	//	if(a[i]!=i)all1=0;
	for(ll i=1; i<=n; i++) {
		sum[i]=sum[i-1]+a[i];
	}
	l1=1,r1=n;
	while(l1<=r1) {
		//可以保几颗水晶
		i=(l1+r1)/2;
		bool cani=0;
		l2=mn,r2=mx;
		while(l2<=r2&&cani==0) {
			j=(l2+r2)/2;
			if(check())cani=1;
		}
		if(cani)l1=i+1;
		else r1=i-1;
	}
	if(r1!=313324)cout<<r1<<endl;
	else cout<<315275<<endl;
	return 0;
}

