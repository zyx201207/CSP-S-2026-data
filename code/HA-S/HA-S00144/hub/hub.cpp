#include<bits/stdc++.h>
using namespace std;

vector<int> e[1000005];
int fa[1000005];
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
bool pan(int x,int y){
	if(find(x)==find(y)) return true;
	return false;
}
void plus(int x,int y){
	x=find(x);
	y=find(y);
	fa[y]=fa[x];
}
int n,c,t,k;
int cnt=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		int u,v;
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	return 0;
}
