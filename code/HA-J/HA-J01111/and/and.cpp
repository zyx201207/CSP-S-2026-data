#include<bits/stdc++.h>
using namespace std;
int a[200010],b,n,ans,m;
void dfs(int r,int u,int t){
	if(t>=m){
		ans=max(ans,u);
		return ;
	}
	for(int i=r+1;i<=n;i++){
		int y=u&a[i];
		if(u==0){
			y=a[i];
		}
		t++;
		dfs(i,y,t);
		t--;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}

