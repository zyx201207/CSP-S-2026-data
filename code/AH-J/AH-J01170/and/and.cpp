#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int mx=-1e9;
int j;
void dfs(int i,int cnt,int h){
	if(i>n){
		return;
	}
	if(cnt>m){
		return ;
	}
	if(cnt==m){
		
		mx=max(mx,h);
		return;
	}
	if(j!=i){
		dfs(i+1,cnt+1,(h&a[i]));
	}
	dfs(i+1,cnt,h);
	
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<n;i++){
		j=i;
		dfs(0,1,a[i]);
		
	}
	
	cout<<mx;
	
	return 0;
}
