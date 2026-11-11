#include<bits/stdc++.h>
using namespace std;
int n,a[200001],maxx,mk[200001],m;
void dfs(int j,int ans){
	if(j==m){
		maxx=max(maxx,ans);
	}
    for(int i=1;i<=n;i++){
    	if(mk[i]!=1){
    		mk[i]=1;
    		dfs(j+1,ans and a[i]);
    		mk[i]=0;
		}
	}	


} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++){
		mk[i]=1;
		dfs(0,a[i]);
		mk[i]=0;
	}
	cout<<maxx;
}
