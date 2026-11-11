#include<bits/stdc++.h>
using namespace std;

bool vis[200010];
long long n,m,a[200010],ans,g;
void dfs(long long g,long long _len){
	if(_len==m){
		ans=max(ans,g);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1 || _len==0 && i==1)continue;
		vis[i]=1;
		dfs(g&a[i],_len++);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	dfs(a[1],0);
	cout<<ans;
}
