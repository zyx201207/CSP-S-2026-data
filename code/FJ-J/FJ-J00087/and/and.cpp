#include"bits/stdc++.h"
using namespace std;
int n,ans,m,a[200005],vis[25];
void dfs(int l,int w){
	if(l==m){
		ans=max(ans,w);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(l+1,w&a[i]);
			vis[i]=0;
		}
	}
}
bool cmp(int c1,int c2){
	return c1>c2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}
		cout<<ans;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1)ans=a[i];
			else ans&=a[i];
		}
		cout<<ans;
	}else if(n<=2000 and m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1,cmp);
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
