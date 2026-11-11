#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1,x[200008],v[200008];
void dfs(int k,int b){
	if(k==m){
		ans=max(ans,b);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(b!=-9) dfs(k+1,b&x[i]);
			else dfs(k+1,x[i]);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	dfs(0,-9);
	cout<<ans;
	return 0;
}
