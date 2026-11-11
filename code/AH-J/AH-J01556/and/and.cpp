#include<bits/stdc++.h>
using namespace std;
int a[200001];
int m,n;
int maxn=0;
int dfs(int i,int s){
	if(i<=n){
		if(s<=m){
			int c=max((a[i]&dfs(i+1,s+1)),dfs(i+1,s));
			maxn=max(maxn,c);
			return c;
		}
	}
	
	return -1;
	
	
}
int main(){
	freopen("and.in","r",stdin);
	freoprn("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	dfs(1,0);
	cout<<maxn;
	return 0;
}

