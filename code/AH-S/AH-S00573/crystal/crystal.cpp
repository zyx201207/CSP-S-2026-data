#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans=0,b[500005],cnt;
void dfs(ll i,ll m){
	cnt++;
	if(m<=0||i>n){
		for(ll i=1;i<=n;i++){
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		ll cnt=1;
		for(ll i=1;i<=n;i++){
			if(b[i]==b[i+1]){
				cnt++;
			}
			else{
				ans=max(ans,cnt);
				cnt=1;
			}
		}
		return ;
	}
	for(ll j=i;j<=n;j++){
		a[i]++;
		dfs(i+1,m-1);
		a[i]--;
		dfs(i+1,m);
		a[i]++;
		dfs(i,m-1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1,m);
	cout<<ans;
	return 0;
}
