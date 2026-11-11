#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll cnt[300001];
ll a[500001];
queue<ll> q;
bool solve(ll x){
	queue<ll> t=q;
	while(!t.empty()){
		if(t.front()==x)return true;
		t.pop();
	}
	return false;
}
void k(){
	while(!q.empty()){
		q.pop();
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(solve(a[j]))k();
			q.push(a[j]);
		}
		while(!q.empty()){
			cnt[q.front()]++;
			q.pop();
		}
	}
	for(ll i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
