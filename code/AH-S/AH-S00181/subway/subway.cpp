#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef pair<int,int> pll;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int c,n,m,d,q,w[N],k,a[N],t[N],x,y;
int head[N],cnt,used[N];
long long dis[N],ans[100005];
struct node{
	int to,next,w;
}e[2*N];
struct nd{
	int id,s,ed;
}rcd[100005];
bool cmp(nd k1,nd k2){
	return k1.s<k2.s;
}
void add(int u,int v,int w){
	e[++cnt].to=v;e[cnt].w=w;
	e[cnt].next=head[u];head[u]=cnt;
}
void dij(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(used,0,sizeof(used));
	priority_queue<pll,vector<pll> ,greater<pll> > q;
	dis[st]=0;
	q.push({dis[st],st});
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(used[now]==1) continue;
		used[now]=1;
		for(int i=head[now];i;i=e[i].next){
			int to=e[i].to;
			if(!used[to]){
				dis[to]=min(dis[to],dis[now]+e[i].w);
				q.push({dis[to],to});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			a[j]=read(),t[j]=read();
			for(int pos=j-1;pos>=1;pos--){
				add(a[j],a[pos],t[j]+t[pos]);
				add(a[pos],a[j],t[j]+t[pos]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		x=read(),y=read();
		rcd[i].id=i;rcd[i].s=x;rcd[i].ed=y;
	}
	sort(rcd+1,rcd+q+1,cmp);
	for(int i=1;i<=q;i++){
		if(rcd[i-1].s==rcd[i].s){
			ans[rcd[i].id]=dis[rcd[i].ed]+w[rcd[i].s]+w[rcd[i].ed];
		}
		else{
			dij(rcd[i].s);
			ans[rcd[i].id]=dis[rcd[i].ed]+w[rcd[i].s]+w[rcd[i].ed];
		}
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
