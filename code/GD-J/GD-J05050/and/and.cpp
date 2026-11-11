//and 35 
#include<bits/stdc++.h>
using namespace std;
long long n,m,zz=0;
long long a[200005];
bool vis[200005];
void dfs(int x,int z){
	if(x==m+1){
		long long ans=-1;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				if(ans==-1){
					ans=a[i];
				}else{
					ans&=a[i];
				}
			}
		}
		zz=max(zz,ans);
		return ;
	}
	if(m-x==n-z+1){
		long long ans=-1;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				if(ans==-1){
					ans=a[i];
				}else{
					ans&=a[i];
				}
			}else if(i>n-z+1){
				if(ans==-1){
					ans=a[i];
				}else{
					ans&=a[i];
				}
			}
		}
		zz=max(zz,ans);
		return ;
	}
	vis[z]=1;
	dfs(x+1,z+1);
	vis[z]=0;
	dfs(x,z+1);
}
int main(){
	freopen("and .in","r",stdin);
	freopen("and .out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(1,1);
	cout<<zz;
	return 0;
}
/*
5 3
31 3 1 15 7
4 2
3 15 12 12
*/
