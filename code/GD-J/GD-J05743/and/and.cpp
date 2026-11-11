#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans=0;
int vis[200005];
void dfs(int x,long long mx){
	if(x==m){
		ans=max(ans,mx);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1,mx&a[i]);
			vis[i]=0;
		} 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long v=0,w;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) w=a[i];
		else w=w&a[i];
		v=max(v,a[i]);
	} 
	if(m==1){
		cout<<v;
		return 0;
	}
	if(m==n){
		cout<<w;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++) ans=max(ans,w&a[i]);
		cout<<ans;
		return 0;
	}else {
		for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
		} 
		cout<<ans;
	}
	
} 
