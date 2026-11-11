#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],ma,n,m;
bool vis[N];
void dfs(int x,int ans){
	if(x==m){
		ma=max(ma,ans);
		return;
	}
	if(ans==0){
		for(int i=1;i<=n;i++){
			if(!vis[a[i]]){
				vis[a[i]]=1;
				dfs(x+1,a[i]);
				vis[a[i]]=0;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(!vis[a[i]]){
				vis[a[i]]=1;
				dfs(x+1,ans&a[i]);
				vis[a[i]]=0;
			}
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0);
	cout<<ma;
	return 0;
}
