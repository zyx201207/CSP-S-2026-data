#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
void dfs(int x,int y,int z){
	if(z<=ans)return;
	if(x==m){
		ans=max(ans,z);
		return;
	}
	for(int i=y+1;i<=n;i++)dfs(x+1,i,(z&a[i]));
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dfs(1,i,a[i]);
	cout<<ans;
}
