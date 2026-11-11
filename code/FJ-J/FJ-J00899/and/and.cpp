#include<bits/stdc++.h>
using namespace std;
int a[200001],n,m,l,ans=-1;
bool vis[200001];
int dfs(int c,int z){
	if(c>m)return z;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans=max(ans,dfs(c+1,(z==-1?a[i]:a[i]&z)));
			vis[i]=0;
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	cout << dfs(1,-1) << '\n';
	return 0;
}
