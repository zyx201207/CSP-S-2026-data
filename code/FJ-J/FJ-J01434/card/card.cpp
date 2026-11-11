#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 6e5 + 7;

int _, n, m, a[N], h[N], ans[N];
map<int, int> mp;

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	int ls=0;
	for(int i=1;i<=n;i++){
		mp[a[i]]--;
		ans[a[i]]+=h[i-1]+1;
		if(!mp[a[i]]) ls=ans[a[i]];
		else ls=0;
		h[i]=ls;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++){
		if(i!=m)cout<<ans[i]<<" ";
		else cout<<ans[i];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_ = 1;
	while(_--){
		solve();
	}
}
