#include<bits/stdc++.h>
using namespace std;

const int N=505,M=5e5+5;

int tasknumber,n,m,d,q,nodenum,vis[M];

struct Node{
	int w,linenum;
	vector<int> line,pos;
}node[M];
struct Line{
	int k;
	vector<int> a,t;
}line[N];
struct othernum{
	int cnt;
	vector<int> num,t;
}na[M];

struct Edge{
	int w,to,next;
	bool operator<(const Edge &other)const{
		return w>other.w;
	}
}edge[M*4];
int edge_head[M],edge_num;

void edge_add(int u,int v,int w){
	edge_num++;
	edge[edge_num].to=v;
	edge[edge_num].w=w;
	edge[edge_num].next=edge_head[u];
	edge_head[u]=edge_num;
}

int Dijkstra(int start,int end){
	memset(vis,0,sizeof(vis));
	int ans=0;
	priority_queue<Edge> q;
	Edge k;
	k.to=start;
	k.w=0;
	q.push(k);
	while(!q.empty()){
		int nowp=q.top().to,noww=q.top().w;
		q.pop();
		if(nowp==end)return noww;
		if(vis[nowp])continue;
		vis[nowp]=1;
		for(int i=edge_head[nowp];i;i=edge[i].next){
			Edge o;
			o.to=edge[i].to;
			o.w=edge[i].w+noww;
			q.push(o);
		}
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>tasknumber>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		scanf("%d",&node[i].w);
		na[i].num.push_back(0);
		na[i].t.push_back(0);
	}
	for(int i=1;i<M;i++){
		node[i].pos.push_back(0);
		node[i].pos.push_back(0);
	}
		
	for(int i=1;i<=n;i++){
		scanf("%d",&line[i].k);
		line[i].a.push_back(0);
		line[i].t.push_back(0);
		for(int j=1;j<=line[i].k;j++){
			int aa,tt;
			scanf("%d%d",&aa,&tt);
			nodenum++;
			na[aa].num.push_back(nodenum);
			na[aa].t.push_back(tt);
			na[aa].cnt++;
			node[nodenum].line.push_back(i);
			node[nodenum].pos.push_back(j);
			node[nodenum].linenum++;
			line[i].a.push_back(nodenum);
			line[i].t.push_back(tt);
			if(j!=1){
				edge_add(line[i].a[j],line[i].a[j-1],0);
				edge_add(line[i].a[j-1],line[i].a[j],0);
			}
		}
	}
//	for(int i=1;i<=nodenum;i++){
//		for(int j=edge_head[i];j;j=edge[j].next){
//			cout<<i<<" "<<edge[j].to<<endl;
//		}
//	}
//	
//	cout<<endl;
//	for(int now=1;now<=m;now++){
//		for(int s=1;s<=na[now].cnt;s++){
//			cout<<na[now].num[s]<<" ";
//		
//		}cout<<endl;
//	}
			
	//cout<<endl;
	
	for(int now=1;now<=m;now++){
		for(int s=1;s<=na[now].cnt;s++){
			for(int e=1;e<=na[now].cnt;e++){
				if(s==e)continue;
				int snum=na[now].num[s],st=na[now].t[s];
				int ennum=na[now].num[e],et=na[now].t[e];
				//cout<<st<<" "<<et<<endl;
				edge_add(snum,ennum,st+et);
			}
		}
	}
	
	while(q--){
		int start,end,ans=INT_MAX;
		cin>>start>>end;
		for(int s=1;s<=na[start].cnt;s++){
			for(int e=1;e<=na[end].cnt;e++){
				int startnum=na[start].num[s],st=na[start].t[s];
				int endnum=na[end].num[e],et=na[end].t[e];
				//cout<<startnum<<" "<<endnum<<endl;
				int sum=node[start].w+node[end].w+st+et;
				//cout<<sum<<" ";
				sum+=Dijkstra(startnum,endnum);
				//cout<<sum<<endl;
				ans=min(ans,sum);
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}


