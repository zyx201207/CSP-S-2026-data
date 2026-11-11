#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long maxs=-1e9;
long long a[N];
unordered_map<long long,bool> vis;
void dfs(long long tot,int now,int num) {
	if(vis[tot]) return ;
	if(num>=m) {
		maxs=max(maxs,tot);
		return ;
	}
	vis[tot]=1;
	for(int i=now+1;i<=n;i++) dfs(tot&a[i],i,num+1);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dfs(a[i],i,1);
    cout<<maxs;
	return 0;
}
//Ren Boda
