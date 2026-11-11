#include<bits/stdc++.h>
#define mk make_pair
#define fir first
#define sec second
using namespace std;

inline int read(){char ch=getchar();int xxx=0,yyy=1;
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1000005,inf=0x3f3f3f3f;

int n,k;
int hd[maxn],to[maxn<<1],nxt[maxn<<1],cnt=1;
void add(int u,int v){
	to[++cnt]=v;nxt[cnt]=hd[u];hd[u]=cnt;
}
int ok[maxn<<1];
pii l1[maxn],l2[maxn];
int cur,vis[maxn],pa[maxn],dep[maxn];
int now,s,t,lca;
int ans;
void dfs(int x,int fa){
	pa[x]=fa;dep[x]=dep[fa]+1;
	l1[x]=mk(-1,x);l2[x]=mk(-1,x);
	vis[x]=cur;
	for(int i=hd[x];i;i=nxt[i]){
		int y=to[i];
		if(y==fa||ok[i])continue;
		dfs(y,x);
		if(l1[x]<l1[y])l2[x]=l1[x],l1[x]=l1[y];
		else if(l1[x]<l1[y])l2[x]=l1[y];
	}
	++l1[x].fir;++l2[x].fir;
	if(l1[x].fir+l2[x].fir>now){
		now=l1[x].fir+l2[x].fir;
		s=l1[x].sec;t=l2[x].sec;lca=x;
	}
}
int _(int x){
	now=0;
	dfs(x,0);
	int mid=now>>1,p=0;
	for(int i=1;i<=mid;i++){
		s=pa[s];t=pa[t];
	}
	if(dep[s]<dep[t])p=t;
	else p=s;
	return p;
}
int X,Y;
pii ck(int x,int d){
	int mn=d,ret=0;
	for(int i=hd[x];i;i=nxt[i]){
		int y=to[i];
		if(y==pa[x]||ok[i])continue;
		pii tmp=ck(y,d);
		ret+=tmp.fir;
		mn=min(mn,tmp.sec);
	}
	if(mn<0)ret++;
	return mk(ret,mn-1);
}
bool chk(int d){
	return ck(X,d).fir+ck(Y,d).fir<=k;
}
void slv(){
	++cur;
	X=0,Y=0;
	for(int i=1;i<=n;i++){
		if(vis[i]!=cur){
			if(!X)X=_(i);
			else Y=_(i);
		}
	}
//	cout<<"XY"<<' '<<X<<' '<<Y<<endl;
	int l=0,r=ans,mid;
	while(l<=r){
		mid=l+r>>1;
		if(chk(mid)){
			r=mid-1;
			ans=mid;
		}else l=mid+1;
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--){
		cin>>n>>k;
		cnt=0;
		ans=inf;
		for(int i=1;i<=n;i++){
			hd[i]=0;
		}
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			add(u,v);
		}
		for(int i=2;i<=cnt;i+=2){
			ok[i]=1;ok[i^1]=1;
			slv();
			ok[i]=0;ok[i^1]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
