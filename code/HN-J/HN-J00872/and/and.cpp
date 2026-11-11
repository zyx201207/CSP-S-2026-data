#include<bits/stdc++.h>
using namespace std;
int n,a[110000],m,maxl=INT_MIN;
void dfs(int s,int i,int x){
	cout<<x<<endl;
	if(i>n) return ;
	if(s==m){
		cout<<x;
		maxl=max(maxl,x);
		return ;
	}
	dfs(s,i+1,x);
	if(x!=-1){
		dfs(s+1,i+1,x and a[i]);
	}
	else dfs(s+1,i+1,a[i]);
	return ;
}
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,-1);
	int A=12,B=15;
	cout<<maxl;
	return 0;
}
/*
4 2
3 15 12 12
*/

