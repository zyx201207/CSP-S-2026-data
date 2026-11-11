#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
template<typename T>
void read(T &x){
	char ch=getchar();bool fg=0;x=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') fg=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=(fg?-x:x);
	return ;
}
const ll inf=1e16;
ll n,m,k,z,x,s,p,y,ans;
int d;
ll gt[505][505];
ll w[500005];
struct node{
	int id;
	ll v;
};
vector<node> a[500005];
vector<node> b[505];
int len;
bool bz[505];
ll f[505][505];
struct point{
	int id;
	ll v;
};
struct cmp{
	bool operator ()(point a,point b){return a.v>b.v;}
};
priority_queue<point,vector<point>,cmp> hp;
void dij(int st){
	while(!hp.empty()) hp.pop();
	for(int i=1;i<=n;i++) f[st][i]=inf,bz[i]=0;
	f[st][st]=0,bz[st]=1;
	for(int i=1;i<=n;i++){
		if(i==st) continue;
		f[st][i]=gt[st][i];
		hp.push((point){i,f[st][i]});
	}
	while(1){
		while(!hp.empty()&&bz[hp.top().id]==1)
			hp.pop();
		if(hp.empty()) break;
		int u=hp.top().id;hp.pop();
		bz[u]=1;
		for(int i=1;i<=n;i++){
			if(f[st][i]>f[st][u]+gt[u][i]){
				f[st][i]=f[st][u]+gt[u][i];
				hp.push((point){i,f[st][i]});
			}
		}
	}
	return ;
}
int main(){
	//subway
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int tid,tz;
	read(tid),read(n),read(m),read(d),read(tz);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			gt[i][j]=inf;
		gt[i][i]=0;
	}
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++){
		read(len);
		for(int j=1;j<=len;j++){
			int id;
			read(id),read(x);
			b[i].push_back((node){id,x});
			a[id].push_back((node){i,x});
		}
	}
	for(int i=1;i<=n;i++){
		for(node h:b[i]){
			int u=h.id;x=h.v;
			for(node j:a[u]){
				int v=j.id;y=j.v;
				gt[i][v]=min(gt[i][v],x+y);
			}
		}
	}
	for(int i=1;i<=n;i++) dij(i);
	int st,en;
	while(tz--){
		ll ans=inf;
		read(st),read(en);
		for(node i:a[st]){
			for(node j:a[en]){
				ans=min(ans,i.v+j.v+f[i.id][j.id]+w[st]+w[en]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}