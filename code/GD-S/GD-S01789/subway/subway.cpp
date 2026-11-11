#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL C,n,m,D,T;
LL w[500005],a[500005],dis[2000005];
LL head[2000005],nxt[4000005],cnt;
struct tni{
	LL x,val;
}to[4000005];
struct qy{
	LL s,t,id,ans;
}q[2000005];
inline void add(LL u,LL v,LL w){
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]={v,w};
}
struct heap{
	LL d[2000005],tot;
	inline bool cmp(LL x,LL y){
		return dis[x]<dis[y];
	}
	inline void pop(){
		swap(d[1],d[tot--]);
		LL t=1;
		while(t*2<=tot){
			if(t*2+1<=tot){
				if(cmp(d[t*2],d[t])){
					if(cmp(d[t*2],d[t*2+1])) swap(d[t],d[t*2]),t=t*2;
					else swap(d[t],d[t*2+1]),t=t*2+1;
				}
				else if(cmp(d[t*2+1],d[t])) swap(d[t],d[t*2+1]),t=t*2+1;
				else break;
			}
			else{
				if(cmp(d[t*2],d[t])) swap(d[t],d[t*2]),t=t*2;
				else break;
			}
		}
	}
	inline void push(LL x){
		d[++tot]=x;
		LL t=tot;
		while(t>1&&cmp(d[t],d[t/2])){
			swap(d[t],d[t/2]);
			t/=2;
		}
	}
}d;
inline bool cmp1(qy x,qy y){
	return x.s<y.s;
}
inline bool cmp2(qy x,qy y){
	return x.id<y.id;
}
inline void solve(LL s){
	for(LL i=1;i<=m;i++) dis[i]=1e18;
	dis[s]=0;
	d.push(s);
	while(d.tot){
		LL u=d.d[1];
		d.pop();
		for(LL i=head[u];~i;i=nxt[i]){
			LL v=to[i].x;
			if(dis[v]>dis[u]+to[i].val){
				dis[v]=dis[u]+to[i].val;
				d.push(v);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	cin>>C>>n>>m>>D>>T;
	for(LL i=1;i<=m;i++){
		cin>>w[i];
	}
	for(LL k=1;k<=n;k++){
		LL len;
		cin>>len;
		for(LL i=1;i<=len;i++){
			LL t;
			cin>>a[i]>>t;
			m++;
			add(a[i],m,t),add(m,a[i],t);
			if(i>1){
				add(m,m-1,0);
				add(m-1,m,0);
			}
		}
	}
	for(LL i=1;i<=T;i++) cin>>q[i].s>>q[i].t,q[i].id=i;
	stable_sort(q+1,q+T+1,cmp1);
	for(LL i=1;i<=T;i++){
		if(i==1||q[i].s!=q[i-1].s){
			solve(q[i].s);
		}
		q[i].ans=dis[q[i].t]+w[q[i].s]+w[q[i].t];
	}
	stable_sort(q+1,q+T+1,cmp2);
	for(LL i=1;i<=T;i++){
		cout<<q[i].ans<<endl;
	}
	return 0;
}
