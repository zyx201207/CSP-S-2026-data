#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=0,a[200005],vis[200005];
void dfs(long long id,long long s){
	if(id==m){
		maxn=max(s,maxn);		
		return;
	}
	else{
		for(long long i=1;i<=n;i++){
			if(vis[i]==0){
				s&=a[i];
				vis[i]=1;
				dfs(id+1,s);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(long long i=1;i<=n;i++){
		vis[i-1]=0;
		vis[i]=1;
		dfs(1,a[i]);
	}	
	cout<<maxn;
}
