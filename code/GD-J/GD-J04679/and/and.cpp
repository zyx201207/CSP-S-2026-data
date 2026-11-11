#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200086];
int f=0;

int dfs(int deep,int last,int ans){
	if(deep>=m){
		f=max(f,ans);
		return 0;
	}
	for(int i=last+1;i<=n;++i){
		if(deep==0){
			dfs(1,i,a[i]);
		}
		else{
			dfs(deep+1,i,(ans&a[i]));
		}
	}
	return 0; 
} 

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	} 
	dfs(0,0,0);
	cout<<f;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
