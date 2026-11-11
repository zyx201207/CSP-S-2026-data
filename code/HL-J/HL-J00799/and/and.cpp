#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e5+5;
ll n,m,a[N],ans;
vector<int> path;
void dfs(int dep,int len){
	if (dep>n){
		return;
	}
	if (len==m){
		ll sum=path[0];
		for (const int i:path){
			sum&=i;
		}
		ans=max(sum,ans);
	}
	
	dfs(dep+1,len);
	
	dfs(dep+1,len+1);
	path.push_back(a[dep]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)cin >> a[i];
	dfs(1,1);
	cout << ans;
}