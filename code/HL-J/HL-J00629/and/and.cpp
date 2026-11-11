#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[201000],cnt=0;
inline void check(ll l,ll sum,ll res){
	if(l==n+1){
		if(sum==m)
			cnt=max(cnt,res);
		return;
	}
	if(res!=-1)check(l+1,sum+1,(res&a[l]));
	else check(l+1,sum+1,a[l]);
	check(l+1,sum,res);
}
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans<<"\n";
		return;
	}
	if(m==2){
		ll ans=1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,(a[i]&a[j]));
		cout<<ans<<"\n";
		return;
	}
	if(m==n){
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans<<"\n";
		return;
	}
	check(1,0,-1);
	cout<<cnt<<"\n";
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
