#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pub push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const int DC=1;
const ll mod=0;
const int N=1000005;

int _c;
int n,k;
vector<int>v[N];
int f[N][20],dep[N];
void dfs(int now,int fa){
	f[now][0]=fa;
	for(int i=1;i<20;i++)f[now][i]=f[f[now][i-1]][i-1];
	dep[now]=dep[fa]+1;
	for(auto i:v[now])if(i^fa)dfs(i,now);
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int t=19;~t;t--)if((dep[x]-dep[y])>>t&1)x=f[x][t];
	if(x==y)return x;
	for(int t=19;~t;t--)if(f[x][t]!=f[y][t])x=f[x][t],y=f[y][t];
	return f[x][0];
}
int dis(int x,int y){return !x||!y?-1:dep[x]+dep[y]-2*dep[lca(x,y)];}

int R;


struct dia{
	int v,p1,p2;
	bool operator<(const dia&b)const{return v<b.v;}
}f1[N],f2[N];
dia p2d(int x,int y){return{dis(x,y),x,y};}
dia p2d(int x){return{0,x,x};}
dia operator+(const dia&a,const dia&b){
	return max({a,b,p2d(a.p1,b.p1),p2d(a.p1,b.p2),p2d(a.p2,b.p1),p2d(a.p2,b.p2)});
}

int d[N],deg[N];
queue<int>q;

void qwq(int now,int fa){
	deg[now]+=v[now].size();
	d[now]=0;
	if(deg[now]==1)q.push(now);
	for(auto i:v[now])if(i^fa)qwq(i,now);
}

int calc(int p,int fa){
	--deg[p];
	qwq(p,fa);
	int ans=0;
	while(!q.empty()){
		int now=q.front();q.pop();
		if(d[now]>=R)++ans;
		for(auto i:v[now])if(i^fa){
			d[i]=max(d[i],d[now]+1);
			if(--deg[i]==1)q.push(i);
		}
	}
	// cerr<<"calc "<<p<<","<<fa<<","<<R<<": "<<ans<<"\n";
	return max(1,ans);
}

bool check(){
	for(int i=2;i<=n;i++){
		int c1=calc(i,f[i][0]);
		if(c1>k)continue;
		int c2=calc(f[i][0],i);
		if(c1+c2<=k)return 1;
	}
	return 0;
}


void dfs2(int now,int fa){
	// cerr<<"asdf "<<now<<","<<fa<<"\n";
	f1[now]=p2d(now);
	for(auto i:v[now])if(i^fa){
		dfs2(i,now);
		f1[now]=f1[now]+f1[i];
	}
}
void dfs3(int now,int fa){
	// cerr<<"fdsa "<<now<<","<<fa<<" "<<f2[now].v<<" "<<f2[now].p1<<","<<f2[now].p2<<"\n";
	vector<dia>qz,hz;
	int l=0;
	for(auto i:v[now])if(i^fa){
		qz.pub(f1[i]);
		hz.pub(f1[i]);
		++l;
	}
	if(!l)return;
	for(int i=1;i<l;i++)qz[i]=qz[i-1]+qz[i];
	for(int i=l-2;~i;i--)hz[i]=hz[i+1]+hz[i];
	int c=0;
	for(auto i:v[now])if(i^fa){
		f2[i]=f2[now]+p2d(now);
		if(c>0)f2[i]=f2[i]+qz[c-1];
		if(c<l-1)f2[i]=f2[i]+hz[c+1];
		c++;
		dfs3(i,now);
	}
	// cerr<<"done "<<now<<"\n";
}

void INIT(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);}
void SOLVE(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].pub(y),v[y].pub(x);
	}
	dep[1]=0;
	dfs(1,1);
	if(k==2){
		dfs2(1,1);
		f2[1]={-1,0,0};
		dfs3(1,1);
		int ans=n;
		for(int i=2;i<=n;i++){
			// cerr<<i<<": "<<f1[i].v<<" "<<f2[i].v<<"\n";
			ans=min(ans,max((f1[i].v+1)/2,(f2[i].v+1)/2));
		}
		cout<<ans<<"\n";
		return;
	}
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		R=mid;
		if(check())ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	INIT();
	int T;
	if(DC)cin>>_c>>T;else T=1;
	for(int _=1;_<=T;_++)SOLVE();
	return 0;
}