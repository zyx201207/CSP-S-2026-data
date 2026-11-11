#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010]={};
int b[200010]={};
int ans=0;
void dfs(int h,int k){
	if(h>m){
		int anl=b[1];
		for(int i=2;i<=m;i++){
			anl&=b[i];
			ans=max(ans,anl);
	    }
	    ans=max(ans,anl);
	    return;
	}
	for(int i=k+1;i<=n-(m-h);i++){
		b[h]=a[i];
		dfs(h+1,i);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		b[1]=a[i];
		dfs(1,i);
	}
	cout<<ans;
}
