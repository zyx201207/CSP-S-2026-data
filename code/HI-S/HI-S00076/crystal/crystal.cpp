#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],sum[N];
void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	return;
}
int search(int l,int r){
	ll res,L=l,R=r;
	while(L<=R){
		ll mid=(L+R)>>1;
		ll s=sum[r-1]-sum[mid-1];
		ll k=(r-mid)*a[r]-s;
		if(k<=m){
			R=mid-1;
			res=r-mid+1;
		} 
		else L=mid+1;
	}
	return res;
}
void solve(){
	int ans=0;
	for(int i=2;i<=n;i++){
		int res=search(1,i);
		ans=max(ans,res);
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	solve();
	return 0;
}

