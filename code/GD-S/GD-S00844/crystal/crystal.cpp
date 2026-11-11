#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using arr=array<ll,2>;
const ll N=1e6+10;
ll n,m,a[N],pre[N],idx[N],ans;
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<n;i++){
		pre[i]=a[i+1]-a[i];
		idx[i]=idx[i-1]+pre[i];
	}
	pre[n]=1e18;
	queue<ll>pq;
	ll cnt=0,ans=1;
	pq.push(1);
	for(ll i=2;i<=n;i++){
		cnt+=pre[i-1]*pq.size();
		pq.push(i);
		//cout<<cnt<<" "<<pq.size()<<"\n";
		while(pq.size()&&cnt>m){
			cnt-=(idx[i-1]-idx[pq.front()-1]);
			pq.pop();
		}
		//cout<<pre[i-1]<<" "<<cnt<<" "<<pq.size()<<"\n";
		ans=max(ans,(ll)(pq.size()));
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ll t;cin>>t;while(t--)
	solve();
	return 0;
}

