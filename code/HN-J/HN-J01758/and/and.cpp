#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int ans;
void dfs(int k, int x, int sum){
	if(x==m){
		ans=max(ans, sum);
		return ;
	}
	if(k>n)return ;
	dfs(k+1, x+1, sum&a[k]);
	dfs(k+1, x, sum);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin>>n>>m;
    ans=-1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)dfs(1, 0, a[i]);
    cout<<ans;
	return 0;
}


