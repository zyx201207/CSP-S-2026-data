#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];int ans;
int ma=-1,vis[N],q[N],top;
void dfs(int x){
	if(x>m){
		for(int i=1;i<=m;i++){
			ans=ans&a[q[i]];
		}ma=max(ans,ma);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			q[++top]=i;
			vis[i]=1;
			dfs(x+1);
			top--;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(n<=20){
		ans=a[1];
		dfs(1);
		cout<<ma;
	}else if(m==n-1){
		ans=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i) ans=ans&a[j];
			}
		}cout<<ans;
		return 0;
	}
	return 0;
}
