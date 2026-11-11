#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
long long ans=0;
void dfs(int wz,int gs,long long zl){
	if(gs==m){
		ans=max(ans,zl);
		return;
	}
	if(wz>n){
		return;
	}
	dfs(wz+1,gs+1,zl&a[wz]);
	dfs(wz+1,gs,zl);                       
}
int main(){
    cin>>n>>m;
    long long fg=(2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2)-1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	dfs(1,0,fg);
    cout<<ans;
	return 0;
}
