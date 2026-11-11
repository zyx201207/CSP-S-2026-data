#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],n,m;
void solve1(){
	ll ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll x=a[i],cost=0,j=i,cnt=0;
		while(j>=1){
			if(cost+(x-a[j])>m)break;
			cost+=(x-a[j]),cnt++;
			j--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
void solve2(){
	ll ans=0;
	sort(a+1,a+n+1);
	ll cost=0,l=1,r=1;
	while(r<=n){
		r++;
		if(r>n)break;
		cost+=(r-l)*(a[r]-a[r-1]);
		while(cost>m){cost-=(a[r]-a[l]);l++;}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=5000){
		solve1();
	}
	else solve2();
	return 0;
}
