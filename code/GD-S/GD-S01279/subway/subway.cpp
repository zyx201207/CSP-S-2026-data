#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	long long dis;
};
struct hassubway{
	int id;
	int pla;
};
int c,n,m,d,q;
long long w[500005];
vector<long long> a[505],t[505];
vector<hassubway> has[500005];
long long dist[500005];
node heap[1000005];
bool vis[500005];
int hsiz;
bool cmp(node x,node y){
	return x.dis<y.dis;
}
void put(node x){
	heap[++hsiz]=x;
	int id=hsiz;
	while(id!=1&&cmp(heap[id],heap[id>>1])){
		swap(heap[id],heap[id>>1]);
		id>>=1;
	}
	return;
}
void get(){
	heap[1]=heap[hsiz];
	hsiz--;
	int id=1;
	while(1){
		int son;
		if((id<<1)>hsiz)return;
		else if((id<<1)==hsiz)son=(id<<1); 
		else if(cmp(heap[id<<1],heap[(id<<1)|1]))son=(id<<1);
		else son=(id<<1)|1;
		if(cmp(heap[son],heap[id])){
			swap(heap[son],heap[id]);
			id=son;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int ki;
		long long aij,tij;
		scanf("%d",&ki);
		for(int j=1;j<=ki;j++){
			scanf("%lld%lld",&aij,&tij);
			a[i].push_back(aij);
			t[i].push_back(tij);
			has[aij].push_back((hassubway){i,j-1});
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		for(int j=1;j<=m;j++){
			dist[j]=(1e18);
			vis[j]=0;
		}
		dist[x]=0;
		put((node){x,0});
		while(hsiz){
			node tp=heap[1];
			get();
			if(vis[tp.id])continue;
			for(int j=0;j<has[tp.id].size();j++){
				for(int k=0;k<a[has[tp.id][j].id].size();k++){
					if(k==has[tp.id][j].pla){
						continue;
					}
					if(dist[tp.id]+(t[has[tp.id][j].id][has[tp.id][j].pla]+t[has[tp.id][j].id][k])<dist[a[has[tp.id][j].id][k]]){
						dist[a[has[tp.id][j].id][k]]=dist[tp.id]+(t[has[tp.id][j].id][has[tp.id][j].pla]+t[has[tp.id][j].id][k]);
						put((node){a[has[tp.id][j].id][k],dist[a[has[tp.id][j].id][k]]});
					}
				}
			}
		}
		printf("%lld\n",w[x]+w[y]+dist[y]);
	}
	return 0;
}
