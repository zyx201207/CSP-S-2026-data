#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans,g[200010];
bool f[200010];
void dfs(int p,int x){
	if(p>m){
		ans=max(ans,x);
		return;
	}
	for(int i=1;i<=n;++i){
		if(p==1){
			f[i]=1;
			dfs(p+1,a[i]);
			f[i]=0;
		}
		else if(!f[i]&&g[p+1]< (x & a[i])){
			f[i]=1;
			g[p+1]=x&a[i];
			dfs(p+1,x & a[i]);
			g[p+1]=0;
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
