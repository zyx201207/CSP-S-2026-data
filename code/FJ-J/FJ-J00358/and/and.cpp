#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ma=-1;
int a[N],b[N];
bool vis[N];
void dfs(int p){
	if(p>m){
		int ans=b[1];
		for(int i=1;i<p;i++){
			ans=ans&b[i];
		}
		ma=max(ma,ans);
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				b[p]=a[i];
				vis[i]=1;
				dfs(p+1);
				b[p]=0;
				vis[i]=0;
			}	
		}	
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=a[1];
	if(n==m){
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==1){
		for(int i=2;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}else if(m==n-1){
		int ans1=1,ans2=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans1=ans1&a[j];	
				}
			}
			ans2=max(ans2,ans1);
		}
		cout<<ans2;
		return 0;
	}else{
		dfs(0);
		cout<<ma;
	}
	return 0;
}

