#include"bits/stdc++.h"
using namespace std;
int fa[100005],n,m,ans;
int find(int x){
	if(fa[x]==x or fa[x]==0)return fa[x]=x;
	return fa[x]=find(fa[x]);
}
struct edge{
	int from,to,weight;
}g[100005];
bool cmp(edge e1,edge e2){
	return e1.weight>e2.weight;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>g[i].from>>g[i].to>>g[i].weight;
	}
	sort(g+1,g+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=find(g[i].from),y=find(g[i].to);
		if(x!=y){
			fa[x]=y;
			ans+=g[i].weight;
		}
	}
	int r=find(g[1].from);
	for(int i=1;i<=n;i++){
		if(find(i)!=r){
			cout<<"orz";
			return 0;
		} 
	}
	cout<<ans;
	return 0;
} 
