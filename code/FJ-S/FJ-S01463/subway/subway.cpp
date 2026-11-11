#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,D=25;
int m,c,n,d,q,dis[M];
struct ditiezhan{
	int zhanting;
	int zt[N]={0};
}dtz[M];
vector<int>lu[N];
int read(){
	int k=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+c-'0';
	return k*f;
}
int solve(int x,int y){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	queue<int>q;
	q.push(x);
	dis[x]=dtz[x].zhanting;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(dtz[u].zt[i]!=0){
				for(int j=1;j<=lu[i][0];j++){
					int v=lu[i][j];
					if(dis[v]>dis[u]+dtz[v].zt[i]+dtz[u].zt[i]&&u!=v) {
						dis[v]=dis[u]+dtz[v].zt[i]+dtz[u].zt[i];
						q.push(v);
					}
				}
			}
		}
	}
	return dis[y]+dtz[y].zhanting;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) dtz[i].zhanting=read();
	for(int i=1;i<=n;i++){
		int k=read();
		lu[i].push_back(k);
		for(int j=1;j<=k;j++) {
			int p=read(),pp=read();
			dtz[p].zt[i]=pp;
			lu[i].push_back(p);
		}
	}
	while(q--){
		int x=read(),y=read();
		printf("%d\n",solve(x,y));
	}
	return 0;
}

