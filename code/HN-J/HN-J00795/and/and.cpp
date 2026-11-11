#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[2000005];
ll v[2000005];
ll ans=-1;
void dfs(ll k,ll cnt){
	if(k>=n||m==cnt){
		ll cnt=0;
		bool tf=1;
		for(ll i=1;i<=n;i++){
			if(v[i]==1 && tf){
				tf=0;
				cnt=a[i];
			}else{
				cnt&=a[i];
			}
		}
		ans=max(ans,cnt);
		return;
	}
	v[k]=1;
	dfs(k+1,cnt+1);
	v[k]=0;
	dfs(k+1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll num;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0);
		cout<<ans;
	}else if(m==1){
		for(ll i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(n==m){
		for(ll i=1;i<=n;i++){
			if(i==1)ans=a[i];
			else ans=(ans&a[i]);
		}
		cout<<ans;
	}else if(m==2){
		ll x,y;
		sort(a+1,a+n+1);
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if((a[i]&a[j])>ans && i!=j){
				ans=max(ans,(a[i]&a[j]));x=a[i],y=a[j];
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
