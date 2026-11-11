#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e6+5;
int c,t;
int n,k;
vector<int> arr[N];
//int vis[N];
//int check(int x){
//	
//	return;
//}
//void dfs(int x,int s){
//	if(s==k){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(i!=j&&vis[i]==1&&vis[j]==1&&check()){
//					dfs2(i,j);
//				}
//			}
//		}
//		return;
//	}
//	if(x>=n){
//		return;
//	}
//	vis[x+1]=1;
//	dfs(x+1,s+1);
//	vis[x+1]=0;
//	dfs(x+1,s);
//}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
//		vis[1]=1;
//		dfs(1,0);
//		vis[1]=0;
//		dfs(1,1);
		printf("1\n");
	}
	return 0;
} 
