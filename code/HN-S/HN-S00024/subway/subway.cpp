#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int c,n,m,o,f,w[500005],idx,d[1000006],e[1000006],le[1000006],ne[1000006],v[500005],vis[500005],h[500005],l[500005],p[500005];
void add(int a,int b,int x){
	idx++;
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx;
	d[idx]=x;
}
void bfs(int a,int b){
	memset(v,0,sizeof(v));
	memset(vis,0,sizeof(vis));
	vis[a]=1;
	q.push(a);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==b){
			cout<<v[u]+w[a]+w[b]<<endl;
		}
		else {
			int cnt=0;
			for(int i=h[u];i!=-1;i=ne[i]){
				cnt++;
				le[e[i]]=u;
				l[cnt]=d[i];
				p[l[cnt]]=i;
			}
			sort(l+1,l+1+cnt);
			for(int i=1;i<=cnt;i++){
				if(!vis[e[p[l[i]]]]){
					q.push(e[p[l[i]]]);
					vis[e[p[l[i]]]]=1;
					v[e[p[l[i]]]]=v[le[e[p[l[i]]]]]+d[p[l[i]]];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>o>>f;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			add(x,i+m,y);
			add(i+m,x,y);
		}
	}
	for(int i=1;i<=f;i++){
		int x,y;
		cin>>x>>y;
		bfs(x,y);
		while(!q.empty()){
			q.pop();
		}
	}
	return 0;
}
