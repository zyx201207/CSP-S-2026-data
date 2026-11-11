#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m,ans;
ll a[200005];
vector<ll> chou;

void dfs(ll idx,ll cnt){
	if(idx>n || cnt==0){
		if(cnt==0){
			ll y=chou[0];
			for(ll x=1;x<chou.size();x++){
				y&=chou[x];
			}
			ans=max(ans,y);
		}
		return;
	}
	chou.push_back(a[idx]);
	dfs(idx+1,cnt-1);
	chou.pop_back();
	dfs(idx+1,cnt);
}

void zj(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
}

void _ma(){
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}

	unique(a+1,a+n+1);
	if(m==n) zj();
	else if(m==1) _ma();
	else if(n>2000 && m>2) _ma();
	else dfs(1,m);
	
	cout<<ans;
	return 0;
}
