#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int n,d;
bool vis[N];
int dfs(int u,int v){
	if(u==v) return 1;
	vis[u]=1;
	int ans=0;
	for(int i=u+1;i<=v;i++){
		if(a[i]-a[u]>d) break;
		if(dfs(u,i)) ans++;
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int mi=INT_MAX,sum=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				memset(vis,0,n);
				if(dfs(u,v)==2){
					sum++;
				}
			}
		}
		cout<<sum;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
