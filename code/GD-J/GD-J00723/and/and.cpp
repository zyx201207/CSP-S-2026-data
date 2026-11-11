#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
long long ans;
long long a[N],b[N];
bool vis[N];
void dfs(int u){
	if(u>m){
		long long cnt=b[1];
		for(int i=2;i<=m;i++){
			cnt&=b[i];
		}
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[u]=a[i];
			dfs(u+1);
			b[u]=0;
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
	}
	dfs(1);
	cout<<ans;
	return 0;
}
