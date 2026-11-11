#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxx=2e5+10;
int node[maxx][3];
int n,m;
int a[maxx];
bool vis[maxx];
int sum=-1;
//void dfs(int step,int ans,int i){
//	if(step==m+1){
//		sum=max(sum,ans);
//		return;
//	}
//	vis[i]=1;
//	dfs(step+1,ans&a[i],i+1);
//	vis[i]=0;
//	dfs(step,ans,i+1); 
//	return;
//}
//int tot=0;
//void insert(int x){
//	int u=0;
//	for(int i=31;i>=1;i--){
//		int c=(x>>i)&1;
//		if(node[u][c]==0){
//			node[u][c]=++tot;
//		}
//		u=node[u][c];
//	}
//}
//int get_ans(int x){
//	int u=0,ans=0;
//	for(int i=31;i>=1;i--){
//		int c=(x>>i)&1;
//		if(node[u][c]==1){
//			ans+=(c<<i); 
//			u=node[u][c];
//		}
//		else{
//			if(node[u][~c]==0) return 0;
//			u=node[u][~c];
//			ans+=((~c)<<i); 
//		}
//	}
//	return ans&x;
//}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(sum,a[i]); 
	}
//	int sum=-1;
//	for(int i=1;i<=n;i++){
//		int num=m;
//		int start=a[i];
//		int ans=get_ans(start);
//		num-=2;
//		for(int j=1;j<=num;j++){
//
//			ans=get_ans(ans);
//		}
//		sum=max(sum,ans);
//	}
//	cout<<sum;
//	dfs(1,2147482647,1);
	cout<<sum;
	return 0; 
}
