#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,ans,a[200005];
bool vis[200005];
void dfs(int b,int s){
	if(s>m)return;
	if(s==m){
		ans=max(ans,b);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs((b)&(a[i]),s+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans)&(a[i]);
		}
		cout<<ans;
	}else if(n<=20){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(a[i],1);
			vis[i]=0;
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max((a[i])&(a[j]),ans);
			}
		}
		cout<<ans;
	}
	return 0;
}

