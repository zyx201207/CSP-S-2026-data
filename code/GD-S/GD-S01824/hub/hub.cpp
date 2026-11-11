#include<bits/stdc++.h>
using namespace std;
int n,k;
struct Edge{
	int v,next;
}e[4000005];
int head[2000005];
int idx=1;
void add(int u,int v){
	e[idx].v=v;
	e[idx].next=head[u];
	head[u]=idx++;
}
struct P{
	int id,d;
	bool color;
}p[2000005];
bool cmp(P a,P b){
	if(a.d==b.d)return a.id<b.id;
	return a.d>b.d;
}
bool st[2000005];
int dist[2000005];
void bfs(queue<int> q){
	while(!q.empty()){
		int ver=q.front();
		q.pop();
		for(int i=head[ver];i;i=e[i].next ){
			int v=e[i].v;
			if(!st[v]){
				st[v]=true;
				q.push(v);
				dist[v]=dist[ver]+1;
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		memset(dist,0,sizeof dist);
		memset(st,0,sizeof st);
		memset(head,0,sizeof head);
		for(int i=1;i<idx;i++)e[i].v=e[i].next=0; 
		idx=1;
		for(int i=1;i<=n;i++)p[i].id=p[i].d=p[i].color=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)p[i].id=i;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			p[u].d++,p[v].d++;
		}
		if(k==n){
			printf("0\n");
			continue;
		}else if(k==n-1){
			printf("1\n");
			continue;
		}
//		sort(p+1,p+n+1,cmp);
		int cnt=0;
		queue<int> q;
		for(int i=1;i<=k;i++){
			bool f=false; 
			P maxx; maxx.d=0,maxx.id=0,maxx.color=0;
			for(int j=1;j<=n;j++){
//				cout<<p[j].d<<" ";
				if(cnt<2){
					if(maxx.d<p[j].d&&!p[j].color){
						maxx=p[j];
						f=true;
					}
				}else{
					if(maxx.d<p[j].d&&!p[j].color){
						for(int z=head[j];z;z=e[z].next){
							if(p[e[z].v].color){
								maxx=p[j];
								f=false;
								break;
							}
						}
					}
				}
			}
			p[maxx.id].color=true;
			if(f)cnt++; 
			q.push(maxx.id);
			st[maxx.id]=true;
			for(int z=head[maxx.id];z;z=e[z].next){
				int v=e[z].v;
				p[v].d--;
			}
//			cout<<endl;
//			cout<<"i="<<i<<" max="<<maxx.id<<" cnt="<<cnt<<endl;
		}
		bfs(q);
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,dist[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
