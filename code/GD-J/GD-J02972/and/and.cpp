#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int n , m , a[50];
void dfs(int x , int v , int ch){
	if(x==n+1){
		if(ch==m)ans = max(ans,v);
		return ;	
	}
	dfs(x+1,v,ch);
	if(v==-1) dfs(x+1,a[x],ch+1);
	else dfs(x+1,v&a[x],ch+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m ;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,-1,0);
	cout <<ans;
	return 0; 
} 

