#include<bits/stdc++.h>
using namespace std;using ll=long long;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c^'-'?1:-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return x*f;}
const int N=1e6+6;
int cid;
int n,k,is[N];
vector<int> E[N];
vector<int> line;
int fa[N],dep[N],mxd[N];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	for(int v:E[u])if(v^fa[u]){
		fa[v]=u;dfs1(v);
	}
}
int nw;
void dfs2(int u,int fa){
	mxd[nw]=max(mxd[nw],dep[u]);
	for(int v:E[u])if(v^fa&&!is[v]){
		dep[v]=dep[u]+1;dfs2(v,u);
	}
}
int nd[N],ct[N];
int st[N],T;
void dfs3(int u,int fa,int x){
	st[++T]=u;nd[u]=0;
	if(T>=x)nd[st[T-x]]=1;
	for(int v:E[u])if(v^fa&&!is[v]){
		dfs3(v,u,x);
	}
	T--;
}
void get(int u,int fa){
	if(u!=nw)ct[nw]+=nd[u];
	for(int v:E[u])if(v^fa&&!is[v]){
		get(v,u);
	}
}
int pr[N],ps[N],sf[N],ss[N];
bool check(int x){
	int L=x,R=line.size()-1-x;
	if(L>=R-1)return 1;
	for(int i=1;i<=n;i++)nd[i]=ct[i]=0;
	for(int i=L+1;i<=R-1;i++){
		dfs3(line[i],0,x);
		nw=line[i];ct[nw]=0;
		get(line[i],0);
	}
	pr[x]=x;ps[x]=0;
	for(int i=L+1;i<=R-1;i++){
		pr[i]=max(pr[i-1],i-max(0,(x-mxd[line[i]])));
		ps[i]=ps[i-1]+ct[line[i]];
	}
	sf[R]=R;ss[R]=0;
	for(int i=R-1;i>=L+1;i--){
		sf[i]=min(sf[i+1],i+max(0,(x-mxd[line[i]])));
		ss[i]=ss[i+1]+ct[line[i]];
	}
	int mn=1e9;
	for(int i=L;i<R;i++){
		int l=pr[i],r=sf[i+1];
		mn=min(mn,ps[l]+ss[r]+l-L+1+R-r+1);
	}
	return mn<=k;
}
void solve(){
	n=rd(),k=rd();
	for(int i=1;i<=n;i++)E[i].clear(),is[i]=mxd[i]=dep[i]=fa[i]=0;
	for(int i=1,u,v;i<n;i++)u=rd(),v=rd(),E[u].push_back(v),E[v].push_back(u);
	line.clear();
	dfs1(1);
	int rt=max_element(dep+1,dep+1+n)-dep;
	dep[rt]=0;fa[rt]=0;
	dfs1(rt);
	int t=max_element(dep+1,dep+1+n)-dep;
	while(t)line.push_back(t),is[t]=1,t=fa[t];
	for(int x:line){
		dep[x]=0;nw=x;
		dfs2(x,0);
//		cerr<<"X: "<<x<<' '<<mxd[x]<<endl;
	}
//	cerr<<endl;
	int l=0,r=line.size()/2,ans=1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cid=rd();
	int t=rd();while(t--)solve();
	return 0;
}
/*


0 1
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
*/


