#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
int maxx=0;
bool vis[200005]; 
void dfs(int u,int sum){
	if(u==m){
		maxx=max(maxx,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1; 
			if(u==0) dfs(u+1,sum | a[i]);
			else dfs(u+1,sum & a[i]);
			vis[i]=0;
		}
	} 
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]); 
		} 
		cout<<maxx;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans &= a[i];
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			int ans;
			if(i!=1) ans=a[1];
			else ans=a[2];
			for(int j=1;j<=n;j++){
				if(i!=j) ans&=a[j];
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx;
	}
	else{
		dfs(0,0);
		cout<<maxx;
	}
	return 0; 
} 
