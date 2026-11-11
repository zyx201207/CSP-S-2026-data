#include<bits/stdc++.h>
using namespace std;
struct node1{
	int v;
	int y=0;
}c[100005];
struct node{
	int b[10005]={0};
	int time;
}a[10005];
int z,m,n,q,r;
int vis[10005]={0};
int dfs(int s,int e,int cost){
	if(s==e)return a[s].b[e];
	int mn=1e9;
	for(int i=1;i<=n;i++){
		if(a[s].b[i]!=0&&vis[i]==0){
			vis[i]==1;
			mn=min(mn,dfs(i,e,cost+=a[s].b[i]));
			vis[i]==0;
		}
	}
	return mn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>z>>m>>n>>q>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i].time;
	}for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>c[j].v>>c[j].y;
		}
		for(int j=1;j<=x;j++){
			for(int k=1;k<=j;k++){
				a[k].b[c[j].v]==c[j].y;
			}
		}
	}
	for(int i=1;i<=r;i++){
		int s,e,cost=a[s].time;
		cin>>s>>e;
		cout<<dfs(s,e,cost);
	}
	return 0;
} 
