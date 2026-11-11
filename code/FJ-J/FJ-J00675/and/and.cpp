#include <bits/stdc++.h>
using namespace std;
long long n,m,a[111111],ans;
bool vis[111111];
void dfs(int x,int y){
	if(y==m){
		if(x>ans){
			ans=x;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&x&a[i]>ans){
			vis[i]=1;
			dfs(x&a[i],y+1);
			vis[i]=0;
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
	if(n>2000&&m!=n-1){
		sort(a+1,a+1+n);
		int p=n;
		ans=a[p];
		for(int i=1;i<=m-1;i++){
			p--;
			ans&=a[p];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(a[i],1);
		vis[i]=0;
	}
	cout<<ans;
	
	
	return 0;
}
