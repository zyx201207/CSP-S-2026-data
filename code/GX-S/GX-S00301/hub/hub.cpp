#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,m,d,p,h,g,ans;
struct node{
	int u;
	int v;
	int dis;
};
bool oerator < (node x,node y){
	return x.dis>y.dis;
}
priority_queue <node> q[1000];
int find(int x){
	if(a[x]!=x) return a[x]=find(a[x]);
	return x;
}
void kruskal(){
	int u=q.top().u;
	int v=q.top().v;
	int dis=q.top().dis;
	q.pop();
	int fu=find(u);
	int fv=find(v);
	if(fu==fv) continue;
	fu=fv;
	if(find(h)==find(g)) ans+=q.top().dis;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
cin>>c>>t;
for(int i=1;i<=t;i++){
	cin>>n>>k;
	for(int j=1;j<=n;j++){
		cin>>q[j].u>>q[j].v;
	}
	kruskal();
	cout<<ans;
}
return 0;
}
