#include<bits/stdc++.h>
using namespace std;
int ma,n,m,a[200005][2];
void dfs(int sum,int ms){
	if(ms) {
		ma=max(sum,ma);	
		for(int i=0;i<n;i++) a[i][1]=0;
	}	
	for(int i=0;i<n;i++){
		if(a[i][1]==1) continue;
		dfs(sum&a[i][0],ms-1);
		a[i][1]=1;
	}	
	return;
}	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=0;i<n;i++) cin>>a[i][0];
	dfs(0,m);
	cout<<ma;
	return 0;
}	
