#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=0;
bool vis[200005];
void dfs(int x,int e){
	if(x==0){
		ans=max(ans,e);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x-1,(e&a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1)ans=ans&a[i];
		else ans=a[i];
	}
	if(m!=n){
		ans=0;
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(m-1,a[i]);
		vis[i]=0;
	}
	}
	cout<<ans;
	return 0;
} 
