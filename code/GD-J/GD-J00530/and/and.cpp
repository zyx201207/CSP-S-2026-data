
#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
void dfs(int k,int g,int s){
	if(g==0){
		ans=max(ans,s);
		return ;
	}
	for(int i=k+1;i<=n;i++){
		if(g==m){
			dfs(i,g-1,(a[i]));
		}
		else{
			dfs(i,g-1,(s&a[i]));
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	int maxx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	dfs(0,m,0);
	cout<<ans;
	return 0;
} 

