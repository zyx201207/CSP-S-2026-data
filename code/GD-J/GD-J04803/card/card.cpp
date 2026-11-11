#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+9;
int n,m;
int ans[N],a[N];
int vis[N];
void solve(){
	for(int i = 1;i <= n;i++){
		vector<int> v;
		fill(vis+1,vis+n+1,0);
		for(int j = i;j <= n;j++){
			if(vis[a[j]]){
				while(v[v.size()-1] != a[j]) vis[v[v.size()-1]]--,v.pop_back();
				v.pop_back();
				vis[a[j]]--;
			}
			v.push_back(a[j]);
			vis[a[j]]++;
		}
		for(int x : v) ans[x]++;
	}
	for(int i = 1;i <= m;i++) cout<<ans[i]<<" ";
	exit(0);
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	solve();
	return 0;
}
