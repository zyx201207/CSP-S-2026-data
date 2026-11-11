#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
long long a[200005];
bool vis[200005];
void dfs(int k,long long now,int las){
	if(k>m){
		ans=max(ans,now);
		return;
	}
	if(now<ans) return;
	for(int i=las+1;i<=n-m+k-1;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(k+1,now&a[i],i);
			vis[i]=false;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1073741823,0);
	cout<<ans;
} 
