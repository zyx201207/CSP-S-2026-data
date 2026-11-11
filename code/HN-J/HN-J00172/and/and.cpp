#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n,m;
int a[N];
int ans = 0;
void dfs(int u,int sa,int s){
	if (u > n){
		if (s == m) ans = max(ans,sa);
		return;
	}
	dfs(u + 1,sa,s);
	if (sa != -114) dfs(u + 1,(sa & a[u]),s + 1);
	else dfs(u + 1,a[u],1);
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	dfs(1,-114,0);
	cout<<ans;
	return 0;
}


