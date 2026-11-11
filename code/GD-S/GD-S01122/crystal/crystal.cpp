#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5;

ll n,m;
ll tt;
ll ans;
ll a[N],f[N];
void init(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	return;
}
priority_queue<ll>q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	tt=m;
	for(ll i=n;i>=1;i--){
		if(i==n){
			q.push(a[i]);
			continue;
		}
		q.push(a[i]);
		tt-=(q.top()-a[i]);
		if(tt>=0){
			ll s=q.size();
			ans=max(ans,s);
		}
		else {
			ll pst=q.top();
			if(!q.empty())q.pop();
			tt+=(q.size())*(pst-q.top());
		}
	}
	cout<<ans;
	return 0;
} 
