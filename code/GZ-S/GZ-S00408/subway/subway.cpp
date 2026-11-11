//GZ-S00408
//王怡然
//毕节梁才学校 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,b,T;

typedef long long LL;
typedef pair<LL,int> PII;

int to[1000000+1000+10];//
int nt[1000000+1000+10];
int h[500000+1000+10];
LL w[1000000+1000+10];
int idx;

void add(int x,int y,LL z){
	to[idx]=y;
	w[idx]=z;
	nt[idx]=h[x];
	h[x]=idx;
	idx++;
} 


priority_queue<PII> hp;
bool v[500000+1000+10];
LL d[500000+1000+10];

LL dijkstra(int bg,int ed){
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[bg]=0;
	while(hp.size()>0){
		PII top=hp.top();
		int t=top.second;
		if(!v[t]){
			v[t]=true;
//			if(t==ed) break;
			for(int i=h[t];i!=-1;i=nt[i]){
				int j=to[i];
				if(d[t]+w[i]<d[j]){
					d[j]=d[t]+w[i];
					hp.push((PII){d[j],j});
				}
			}	
		}
	}
	return d[ed];
}

LL a[500000+1000+10]; 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	 
//	freopen("subway2.in","r",stdin);
//	freopen("mytest.out","w",stdout);
	 
	memset(h,-1,sizeof(h));
	scanf("%d%d%d%d%d",&c,&m,&n,&b,&T);//注意n,m的含义 
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x;
			LL t;
			scanf("%d%lld",&x,&t);
			add(x,i+n,t);
			add(i+n,x,t);
		}
	}
	
	
	
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",a[x]+a[y]+dijkstra(x,y));
	｝	
	return 0;
}


