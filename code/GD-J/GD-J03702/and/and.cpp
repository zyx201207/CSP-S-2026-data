#include<bits/stdc++.h>
using namespace std;
struct node{
	int ans,num;
};
int n,m,a[200005],vis[200005],ans=0;
void dfs(int step,int c){
	if(step>n){
		if(c!=m)return;
		int q=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&q==0)q=a[i];
			else if(vis[i])q&=a[i];
		}
		//cout<<endl;
		//for(int i=1;i<=n;i++){
		//	if(vis[i])cout<<i<<" ";
		//}
		//cout<<endl;
		ans=max(ans,q);
		return;
	}
	vis[step]=1;
	dfs(step+1,c+1);
	vis[step]=0;
	dfs(step+1,c);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}
	else if(m==n-1){
		int maxn=0;
		for(int k=1;k<=n;k++){
			int ans;
			if(k==1){
				ans=a[2];
				for(int i=3;i<=n;i++)ans&=a[i];
			}
			else{
				ans=a[1];
				for(int i=2;i<=n;i++){
					if(i==k)continue;
					ans&=a[i];
				}
			}
			maxn=max(ans,maxn);
		} 
		cout<<maxn;
	} 
	else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
