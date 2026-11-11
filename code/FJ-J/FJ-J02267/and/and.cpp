#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool vis[200010];
long long n,m,ans,ans1=0;
void dfs(int x,int cnt){
	if(cnt==m){
		ans1=max(ans,ans1);
		return ;	
	}	
	for(int i=x;i<=n;i++){
		if(cnt==1){
			ans=a[i];	
		}
		if(vis[i]==false){
			ans=ans&a[i];	
		}
		vis[i]=true;
		dfs(i+1,cnt+1);
		vis[i]=false;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	
	if(m==1){
		ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==2){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else{
		dfs(1,1);
		cout<<ans1;
	}
	return 0;
}
