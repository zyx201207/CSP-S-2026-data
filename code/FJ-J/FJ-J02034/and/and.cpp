#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,vis[200005],m,n,a[200005];

void dfs(int x){
	if(x==m){
		cout<<ans;
		return;
	}
	int t=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int x=a[i]&ans;
			int y=ans&a[t];
			if(x>y){
				t=i;
			}
		}
	}
	vis[t]=1;
	ans&=a[t];
	dfs(x+1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);	
	}
	for(int i=1;i<=n;i++){
		if(a[i]==ans){
			vis[i]=1;
			break;
		}
	}
	dfs(1);
	return 0;
}

