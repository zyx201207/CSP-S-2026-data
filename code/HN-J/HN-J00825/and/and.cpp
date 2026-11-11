#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200050],maxn,vis[200050];
void dfs(long long x,long long l,long long ans){
	if(l==m){
		maxn=max(maxn,ans);
		return ;
	}
	for(long long i=x;i<=n;i++){
		if(vis[i]!=1){
			vis[i]=1;
			if(l==0){
				dfs(i,l+1,a[i]);
			}
			else{
				dfs(i,l+1,(ans&a[i]));
				
			}
			vis[i]=0;		
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxn;
	return 0;
}

