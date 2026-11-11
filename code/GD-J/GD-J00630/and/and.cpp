#include<bits/stdc++.h>
using namespace std;
#define ll int
#define st string
ll n,m,top,maxx,vis[200050],ans;//p 某位个数
struct num{
	ll s,tw[32],maxi;//tw二进制拆分 maxi最高位 
}r[200050];
ll check(ll x){
	ll sum=0;
	for(ll i=1;i<=n;i++){
		if(vis[i]==0&&r[i].tw[x]==1)
			sum++;
	}
	if(sum>=m)
		return 1;
	else
		return 0;
}
void change(ll x){
	for(ll i=1;i<=n;i++){
		if(r[i].tw[x]==0)
			vis[i]=1;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>r[i].s;
		top=0;
		ll l=r[i].s;
		while(l){
			r[i].tw[++top]=l%2;
			l/=2;
		}
		r[i].maxi=top;
	}
	for(ll i=30;i>=1;i--){
		if(check(i)){
			ans+=1<<(i-1);
			change(i);
		}
	}
	cout<<ans;
	return 0;
}

