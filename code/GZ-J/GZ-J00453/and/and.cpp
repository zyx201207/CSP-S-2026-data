//GZ-J00453 ¹ùÓê³¿ 
#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
int a[200000];
void dfs(int x,int x1,int s){
	if(x>m) return;
	if(x==m){
	ma=max(ma,s);
	}
	for(int i=x1;i<=n;i++){
		dfs(x+1,i+1,(s&a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		dfs(1,i+1,a[i]);
	}
	cout<<ma;
	return 0;
}
