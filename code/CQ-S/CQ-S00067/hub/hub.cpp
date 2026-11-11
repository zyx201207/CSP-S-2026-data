#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v[500005];
ll fa[500005],arr[500005],ans1[500005],biao[500005],ans=1e8;
		ll n,k;
		queue<ll> q;
void dfs1(ll x,ll f){
	for(ll i=0;i<v[x].size();i++){
		if(!arr[v[x][i]]) continue;
		arr[v[x][i]]=0;
		dfs1(v[x][i],x);
	}
}
ll suan(){
	memset(ans1,0x3f,sizeof(ans1));
	for(ll i=1;i<=n;i++){
		if(biao[i]){
			ans1[i]=0;
			q.push(i);
		}
	}
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		for(ll i=0;i<v[x].size();i++){
			if(ans1[v[x][i]]<=1e8) continue;
			ans1[v[x][i]]=ans1[x]+1;
			q.push(v[x][i]);
		}
	}
	ll t=0;
	for(ll i=1;i<=n;i++) arr[i]=biao[i];
	for(ll i=1;i<=n;i++){
		if(arr[i]){
			arr[i]=0;
			dfs1(i,0);
			t++;
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans=max(ans,ans1[i]);
	}
	if(t>2) return 1e8;
	else return ans;
}
void dfs(ll x,ll s){
	if(s==0){
		ans=min(ans,suan());
		return;
	}
	if(x==0) return;
	dfs(x-1,s);
	biao[x]=1;
	dfs(x-1,s-1);
	biao[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<n;i++){
			ll l,r;
			cin>>l>>r;
			v[l].push_back(r);
			v[r].push_back(l);
		}
		if(c==13||c==14){
			cout<<((n+1)/2+2-k+3)/4<<endl;
		}else{
			dfs(n,k);
			cout<<ans<<endl;
			ans=1e8;
		}
		for(ll i=1;i<=n;i++) v[i].clear();
	}
}
