#include<bits/stdc++.h>
using namespace std;

struct ll{
	int ne;
	int w;
	long long v;
	int y;
}edge[10105];
int p,d,c,m,cnt=0,n;
int head[10105];
long long dis[10105];
bool fl[10105];
int wh[10005];//m
long long ds=0;

inline void add(int x,int y,long long z){
	edge[++cnt].v=z;
	edge[cnt].ne=head[x];
	edge[cnt].y=0;
	edge[cnt].w=y;
	head[x]=cnt;
	edge[++cnt].v=z;
	edge[cnt].ne=head[y];
	edge[cnt].y=wh[y];
	edge[cnt].w=x;
	head[y]=cnt;
}

inline void di(int x,int y){
	int ccc=0x3f3f3f3f,p=-1;
	for(int i=1;i<=ds;i++){
		if(!fl[i]&&ccc>dis[i]){
			ccc=dis[i];
			p=i;
		}
	}
	if(p==-1)return;
	fl[p]=1;
	for(int i=1;i<=ds;i++){
		for(int j=head[p];edge[j].ne!=0;j=edge[j].ne){
			if(dis[edge[j].w]>dis[p]+edge[j].v+edge[j].y&&!fl[j])dis[edge[j].w]=dis[i]+edge[j].v+edge[j].y;
		}
	}
} 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>wh[i];
	int k,a,t;
	ds+=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			ds++;
			cin>>a>>t;
			add(ds,a,t);
		}
	}
	int f,e;
	while(p--){
		cin>>f>>e;
		for(int i=1;i<=ds;i++){
			fl[i]=0;
			dis[i]=0x3f3f3f3f;
		}
		dis[f]=wh[f];
		di(f,e);
		cout<<dis[e]<<'\n';
	}
}
