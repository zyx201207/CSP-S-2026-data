#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],n,m,ans=0;
int vis[101901];
void dfs(int u,int sum){
	vis[u]=1;
	if(u>m)return ;
	if(u==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(u+1,sum&a[i]);
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio();cin.tie();cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	if(n<=20){
//		for(int i=1;i<=n;i++){
//			vis[i]=1;
//			dfs(1,a[i]);
//			memset(vis,0,sizeof vis);
//		}
//		cout<<ans<<'\n';
//	}
	else if(m==1){
		
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<'\n';
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<'\n';
	}
	else if(m==n){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt&=a[i];
		}
	}
	return 0;
}
