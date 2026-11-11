#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[200005],vis[200005],ans;
void dfs(int x,int cnt){
	if(cnt==m+1){
		ans=max(ans,x);
		return;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]!=1){
			vis[i]=1;
			dfs(x&a[i],cnt++);
			vis[i]=0;
		}
	}
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    if(n>100){
    	int ans=0; 
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
    		ans=max(ans,a[i]);
		} 
		cout<<ans;
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(a[i],1);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}


