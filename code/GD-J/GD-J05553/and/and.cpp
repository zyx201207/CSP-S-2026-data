#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[100005];
int dp[10006];
int ans=0;
void dfs(int id,int w){
	if(id==m)
		return;
	if(w==n)
		return;
	ans=max(ans,ans&a[w]);
	dfs(id+1,w+1);
	dfs(id,w+1);
	return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
