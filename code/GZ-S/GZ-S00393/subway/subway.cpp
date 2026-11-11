//毕节梁才学校
//罗悦辉
//GZ-S00393 
#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define PII pair<LL,LL>

struct OP{
	int x,y,id;
};

int c,q,n,m,d;
const int N=510;
const int M=5e5+10;
const int B=M+N;

LL jz[M];

int h[M+N];
int nt[B<<1];
int to[B<<1];
LL w[B<<1];
int idx;

void add(int x,int y,LL z){
	to[idx]=y;
	nt[idx]=h[x];
	h[x]=idx;
	w[idx]=z;
	idx++;
}

OP a[M];
bool cmp(OP A,OP B){
	if(A.x!=B.x) return A.x<B.x;
	else return A.y<B.y;
}
LL ans[M];

bool v[B];
LL ju[B];
priority_queue<PII,vector<PII>,greater<PII> > hp;
void dijkstra(int u){
	memset(v,0,sizeof(v));
	memset(ju,0x3f,sizeof(ju));
	ju[u]=0;
	hp.push((PII){0,u});
	while(!hp.empty()){
		PII tp=hp.top();
		hp.pop();
		int x=tp.second;
		if(v[x]) continue;
		v[x]=true;
		for(int i=h[x];i!=-1;i=nt[i]){
			int j=to[i];
			if(ju[j]>ju[x]+w[i]) ju[j]=ju[x]+w[i],hp.push((PII){ju[j],j});
		}
	}
}

vector<PII> tai[N];
LL erfen(int x,int id){
	int l=0,r=tai[id].size()-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(tai[id][mid].first<=x) l=mid;
		else r=mid-1;
	}
	if(r<=-1||r>=tai[id].size()) return 0x3f3f3f3f3f3f3f3f;
	return tai[id][r].first==x?tai[id][r].second:0x3f3f3f3f3f3f3f3f;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(h,-1,sizeof(h));
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&jz[i]);
	for(int i=1;i<=m;i++){
		int cnt;
		scanf("%d",&cnt);
		for(int j=1;j<=cnt;j++){
			int x;LL z;
			scanf("%d%lld",&x,&z);
			add(x,n+i,z);
			add(n+i,x,z);
			tai[i].push_back((PII){x,z});
		}
		sort(tai[i].begin(),tai[i].end());
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]=(OP){x,y,i};
	}
	
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=m;i++){
		dijkstra(n+i);
		for(int j=1;j<=q;j++){
			int x=a[j].x;
			LL t=erfen(x,i);
			ans[j]=min(ans[j],t+ju[a[j].y]+jz[x]+jz[a[j].y]);
		}
	} 
	for(int j=1;j<=q;j++) printf("%lld\n",ans[j]);
	
	return 0;
}
