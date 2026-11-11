#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[200005];
int maxx=0;
vector<int> a(200005);
void dfs(int xz,int cs){
	if(cs==m){
		maxx=max(maxx,xz);
		return;
	}
	for(int ii=1;ii<=n;ii++){
		if(vis[ii]){
			continue;
		}
		else{
			vis[ii]=1;
			dfs(xz&a[ii],cs+1);
			vis[ii]=0;
		}
	}
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(vis,0,sizeof(vis));

	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(a[i],1);
		vis[i]=0;
	}
	cout<<maxx<<'\n';
	
	return 0;
}
