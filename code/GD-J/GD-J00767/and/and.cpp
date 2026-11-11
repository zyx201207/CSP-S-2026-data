#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using arr=array<ll,2>;
const ll N=1e6+10;
ll n,a[N],m,ans;
map<ll,ll>mp;
array<ll,3>num[N];
void dfs(ll x,ll sum,ll cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if(x>n){
		return ;
	}
	dfs(x+1,sum,cnt);
	//cout<<(cnt==0?a[x]:sum&a[x])<<"\n";
	dfs(x+1,cnt==0?a[x]:sum&a[x],cnt+1);
}
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll sum=0;
	if(n<20){
		dfs(1,0,0);
		cout<<ans;
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(m==1) sum=max(sum,a[i]);
		num[i][2]=a[i];
		num[i][0]=1;
		while(a[i]){
			if(a[i]%2==1) mp[num[i][0]]++,num[i][1]++;
			a[i]/=2;
			num[i][0]++;
		}
	}
	if(m==1) cout<<sum<<"\n";
	for(ll i=1;i<=n;i++){
		while(mp[num[i][0]]<=1&&num[i][0]>=0) num[i][0]--;
		//cout<<num[i][0]<<"\n";
	}
	sort(num+1,num+n+1,greater<array<ll,3>>());
	if(n>20||m==1||m==2){
		ll ans=num[1][2];
		for(ll i=2;i<=m;i++){
			ans&=num[i][2];
		}
		cout<< ans<<"\n";
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ll t;cin>>t;while(t--)
	solve();
	return 0;
}

