#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ls=0,ans=0,b[200010],c[200010]={0};
void dfs(int k){
	if(k>m){
		ls=b[1];
		for(int i=2;i<=m;i++){
			ls=(ls & b[i]);
		}
		ans=max(ans,ls);
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			c[i]=1;
			b[k]=a[i];
			dfs(k+1);
			c[i]=0;
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
	dfs(1);
	cout<<ans;
	return 0;
}
