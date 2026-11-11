#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=LONG_LONG_MAX/5;
int cid,n,m,D,Q;
struct qwq{int S,T,id,ans;}qes[100005];
bool cmp1(qwq x,qwq y){return x.S<y.S;}
bool cmp2(qwq x,qwq y){return x.id<y.id;}
int w[500005],tot[505];
struct wyw{int x,z;};
vector<wyw> e[5000005];
//wyw r[5000005];
//int cnt;
//void add(int x,int y){
//	r[++cnt]={x,y}; int t=cnt;
//	while(t>1&&r[t].z<r[t/2].z){
//		swap(r[t],r[t/2]); t/=2;
//	}
//}
//void pop(){
//	r[1]=r[cnt--]; int t=1;
//	while(t*2<=cnt){
//		int fh=t*2;
//		if(t*2<cnt&&r[fh+1].z<r[fh].z) fh++;
//		if(r[t].z<r[fh].z) return;
//		swap(r[t],r[fh]); t=fh;
//	}
//}
int N;
int d[5000005];
bool flag[5000005];
int st[5000005],top;
int h[5000005],head,tail;
void dij(int S){
//	for(int i=1;i<=N;i++) d[i]=inf,flag[i]=0;
	d[S]=0;/* cnt=0; add(S,0);*/ top=1,st[1]=S;
	head=0,tail=1; h[1]=S; flag[S]=1;
	while(head<tail){
		head++; int x=h[head];
		flag[x]=0;
		for(wyw y:e[x]){
			if(d[y.x]>d[x]+y.z){
				d[y.x]=d[x]+y.z;
				if(flag[y.x]==1) continue;
				h[++tail]=y.x; flag[y.x]=1;
				st[++top]=y.x;
			}
		}
	}
//	for(int iii=1;iii<=N;iii++){
//		while(cnt&&flag[r[1].x]) pop();
//		if(cnt==0) return;
//		int x=r[1].x; flag[x]=1; pop();
//		for(wyw y:e[x]){
//			if(d[y.x]>d[x]+y.z){
//				if(d[y.x]==inf) st[++top]=y.x;
//				d[y.x]=d[x]+y.z;
//				add(y.x,d[y.x]);
//			}
//		}
//	}
	for(int i=1;i<=Q;i++){
		qes[i].ans=min(qes[i].ans,d[qes[i].S]+d[qes[i].T]);
	}
	for(int i=1;i<=top;i++){
		d[i]=inf,flag[i]=0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&cid,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	N=m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&tot[i]); N++;
		for(int j=1;j<=tot[i];j++){
			int x,y; scanf("%lld%lld",&x,&y);
			e[N].push_back({x,y}); e[x].push_back({N,y});
		}
	}
	for(int i=1;i<=Q;i++){
		scanf("%lld%lld",&qes[i].S,&qes[i].T);
		qes[i].ans=inf,qes[i].id=i;
		if(qes[i].S==qes[i].T) qes[i].ans=0;
	}
	for(int i=1;i<=N;i++) d[i]=inf,flag[i]=0;
	for(int i=1;i<=n;i++){
		dij(i+m);
	}
//	sort(qes+1,qes+1+Q,cmp1);
//	int lst=0;
//	for(int i=1;i<=Q;i++){
//		if(lst!=qes[i].S) dij(qes[i].S);
//		qes[i].ans=d[qes[i].T]+w[qes[i].S]+w[qes[i].T];
//	}
//	sort(qes+1,qes+1+Q,cmp2);
	for(int i=1;i<=Q;i++){
		printf("%lld\n",qes[i].ans+w[qes[i].S]+w[qes[i].T]);
	}
	return 0;
}
