#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,m,a[200005];
void dfs(int x,int y,int d){
	if(x==n+1){
		if(y==m){
			ans=max(ans,d);
			return;
		}
		return;
	}
	if(y>m) return;
	dfs(x+1,y,d);
	dfs(x+1,y+1,d&a[x+1]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,-1);
	cout<<ans;
}
