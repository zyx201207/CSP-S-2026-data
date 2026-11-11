#include <iostream>
#include <cstring>
using namespace std;
#define max(aaa,bbb) (aaa>bbb ? aaa:bbb) 
int n,m;
int a[222222],ans,used[222222];
bool vis[222222];
void dfs(int rs,int step){
	if(step==m){
		ans=max(ans,rs);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i] && i>used[step]){
			vis[i]=1;
			used[++step]=i;
			dfs(rs&a[i],step);
			vis[i]=0;
			used[step--]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		used[i]=i;
		dfs(a[i],1);
	}
	cout<<ans;
	return 0;
} 
