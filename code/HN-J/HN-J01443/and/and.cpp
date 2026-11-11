#include<bits/stdc++.h>
using namespace std;
int a[200005],vis[200005],maxn=0,n,m;

void dfs(int x){
	if(x>n){
		int d=0;
		for(int i=1;i<=n;i++) if(vis[i]==1) d++;
		
		if(d==m){
			int t=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					if(t==0) t=a[i];
					else t&=a[i];
				}
			}
			maxn=max(maxn,t);
		}
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1);
		cout<<maxn;
	}
	else{
		if(m==n){
			int ans=a[1];
			for(int i=2;i<=n;i++){
				ans&=a[i];
			}
		}else if(m==2){
			int maxn=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					maxn=max(maxn,a[i]&a[j]);
				}
			}
			cout<<maxn;
		}
	}
} 
