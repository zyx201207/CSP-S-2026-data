#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,d;
ll a[100005],vis[100005];
ll cnt,ans,biao;
void dfs(ll step,ll id) {
	if(step>ans)return ;
	if(id==biao) {
		ans=step;
//		if(step==ans)cnt++;
//		else cnt=0;
		return ;
	}
	for(ll i=id+1; i<=n; i++) {
		if(abs(a[id]-a[i])<=d)
			dfs(step+1,i);
		else return ;
	}
}
void dfs1(ll step,ll id) {
	if(cnt>2)return ;
	if(step>ans)return ;
	if(id==biao) {
		if(step==ans)cnt++;
		else cnt=0;
		return ;
	}
	for(ll i=id+1; i<=n; i++) {
		if(abs(a[id]-a[i])<=d)
			dfs1(step+1,i);
		else return ;
	}
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>t;
	while(t--) {
		ll tmp=0;
		cin>>n>>d;
		for(ll i=1; i<=n; i++)cin>>a[i];
		for(ll i=1; i<=n; i++)
			for(ll j=i+1; j<=n; j++) {
				//memset(vis,0,sizeof vis);
				cnt=0;
				ans=n;
				biao=j;
				dfs(0,i);
				dfs1(0,i);
				//cout<<i<<" "<<j<<" ";
				//cout<<ans<<" "<<cnt<<endl;
				if(cnt==2)tmp++;
			}
		cout<<tmp<<endl;
	}
	return 0;
}

