#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int maxx=0,n,m;
int a[2000005];
void dfs(int d,int ans,int x){
	
	if(d>n||x>=m){
		if(x<m){
			return ;
		}
		maxx=max(ans,maxx);
		return ;
	} 
	else{
		if(ans==0){
			dfs(d+1,a[d],x+1);
		}
		else{
			dfs(d+1,ans&a[d],x+1);
			
		}
		dfs(d+1,ans,x);
	}
	return ;
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	std::ios::sync_with_std(false);
//	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxx;
	return 0;
}
