#include<bits/stdc++.h> 
using namespace std;
int n;
long long d;
int c,t;
struct dao{
	long long x;
	vector<int> nxt;
	bool bokok=false;
}node[20005];

bool bfs(dao u,dao v){
bool book[200005];
for(int i=0;i<=n;i++) book[i]=false;
	dao nw,nt,biao;
	queue<dao> q;
	biao.bokok=true;
	biao.x=0;
	q.push(u);
	q.push(biao);
	bool flag=false;
	while(q.size()>1){
		nw=q.front();
		if(nw.bokok) {
			q.push(nw);
			if(flag) return false;
			q.pop();
			continue;
		}
		q.pop();
		for(int i=0;i<nw.nxt.size();i++){
			if(node[nw.x].nxt[i]==v.x){
						if(flag) return true;
						book[v.x]=false;
						flag=true;
					} 
			if(book[node[nw.x].nxt[i]]) {
				continue;
			}
			q.push(node[node[nw.x].nxt[i]]);
			book[node[nw.x].nxt[i]]=true;
		}
		
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%lld",&c,&t);
	bool yl=true;
	if(c!=0) yl=false;
for(int ii=1;ii<=t;ii++){
	bool xing=true;
	long long ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		node[i].nxt.clear();
	}
	queue<dao>qu;
	bool dengcha=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&node[i].x);
		if(i>2&&(node[i].x-node[i-1].x==node[2].x-node[1].x)&&(node[2].x-node[1].x)*2<=d) dengcha=true;
		if(i>1&&(node[i].x-node[i-1].x>d)) xing=false;
		int h=qu.size();
		for(int j=1;j<=h;j++){
			if(node[i].x-qu.front().x<=d) {
				node[qu.front().x].nxt.push_back(i);
				qu.push(qu.front());
			}
			qu.pop();
		}
		qu.push(node[i]);
	}
	if(xing==false){
		printf("0\n");
		continue;
	}
	xing=false;
	for(int i=1;i<=n;i++){
		if(node[i].nxt.size()>1)
			xing=true;
	}
	if(xing==false) {
		printf("0\n");
		continue;
	}
	for(int u=1;u<n-1;u++)
		for(int v=u+2;v<=n;v++) ans++;
	if(dengcha&&!yl) {
		printf("%lld\n",ans);
		continue;
	}
	for(int u=1;u<n-1;u++){
		for(int v=u+2;v<=n;v++){
			if(bfs(node[u],node[v])){
			ans++;	
			} 
		}
	}
	printf("%lld\n",ans);
}
	return 0;
}
