#include<bits/stdc++.h>
using namespace std;

int n,m,a[200050],maxx=-1e9;
bool vis[200050];
void dfs(int idx,int cnt,int ans,bool f){
	if(cnt>m)return;
	if(idx==n+1){
		if(cnt==m)maxx=max(maxx,ans);
		return;
	}
	if(f==0){
		vis[idx]=1;
		dfs(idx+1,cnt+1,a[idx],1);
		vis[idx]=0;
		dfs(idx+1,cnt,ans,0);
	}else{
		vis[idx]=1;
		dfs(idx+1,cnt+1,(ans&a[idx]),1);
		vis[idx]=0;
		dfs(idx+1,cnt,ans,1);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	}else if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++)maxx=maxx&a[i];
		cout<<maxx;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<maxx;
	return 0;
} 
