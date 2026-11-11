#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=6e5+50;
ll n,m;
ll a[N];
ll ans;
void check(ll x){
	ll now=x,tot=0,sum=0;
	while(now>0){
		if(sum+a[x]-a[now]<=m){
			sum+=a[x]-a[now];
			tot++;	
			ans=max(ans,tot);
		}
		else{
			ans=max(ans,tot);
			return;
		}
		now--;
	}
	ans=max(ans,tot);
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		check(i);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
