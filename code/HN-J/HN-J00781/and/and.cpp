#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int maxx=-1;
int vis[200005];
int sum[200005];
void dfs(int now,int e){
	if(now==m){
		int cnt=sum[1];
		for(int i=2;i<e;i++){
			cnt=cnt&sum[i];
		}
		maxx=max(cnt,maxx);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			sum[e]=a[i];
			dfs(now+1,e+1);
			vis[i]=0;
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
	dfs(0,1);
	cout<<maxx;
	return 0;
} 
