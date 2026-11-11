#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k,dep[1000005],ans,p[1000005],cur,pp[1000005],ct[1000005],m1[1000005],m2[1000005],d[1000005];
int st[1000005][22];
bool is[1000005];
vector<long long> e[1000005];
void dfs(long long u,long long fa){
	dep[u]=dep[fa]+1,st[u][0]=fa;
	for(long long j=1;j<=20;j++)st[u][j]=st[st[u][j-1]][j-1];
	for(long long i=0;i<e[u].size();i++){
		long long v=e[u][i];
		if(v==fa)continue;
		dfs(v,u);
	}
}
long long lca(long long x,long long y){
	if(dep[x]<dep[y])swap(x,y);
	for(long long i=20;i>=0;i--){
		if(dep[st[x][i]]>=dep[y])x=st[x][i];
	}
	if(x==y)return y;
	for(long long i=20;i>=1;i--){
		if(st[x][i]!=st[y][i])x=st[x][i],y=st[y][i];
	}
	return st[x][0];
}
long long find(long long x){ return pp[x]==x?x:pp[x]=find(pp[x]); }
void merge(long long x,long long y){
	long long fx=find(x),fy=find(y);
	if(fx==fy)return ;
	pp[fx]=fy;
}
long long dist(long long x,long long y){
	long long lc=lca(x,y);
	return dep[x]+dep[y]-2*dep[lc];
}
void getdis(long long x,long long fa,long long col,long long dep){
	d[x]=d[fa]+1;
	if(d[x]>d[m1[col]])m2[col]=m1[col],m1[col]=x;
	else if(d[x]>d[m2[col]])m2[col]=x;
	for(long long i=0;i<e[x].size();i++){
		long long v=e[x][i];
		if(v==fa)continue;
		getdis(v,x,col,dep+1);
	}
}
long long f(long long x,long long l1,long long l2){ return min(dist(x,l1),dist(x,l2)); }
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=2e18;
		for(long long i=1,u,v;i<n;i++)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		dfs(1,0);
		if(k==2){
			for(long long i=1;i<=n;i++)getdis(i,0,i,0);
			for(long long o=1;o<=n;o++)for(long long q=o+1;q<=n;q++){
				cur=0;
				bool flag=true;
	//			cout<<st<<'\n';
				for(long long i=0;i<e[o].size();i++)flag&=e[o][i]!=q;
				if(!flag)continue;
				long long p1=m1[o],p2=m2[o],p3=m1[q],p4=m2[q];
				if(p1==0)p1=o;
				if(p2==0)p2=o;
				if(p3==0)p3=q;
				if(p4==0)p4=q;
				ans=min(ans,max(max(f(p1,o,q),f(p2,o,q)),max(f(p3,o,q),f(p4,o,q))));
			}
			cout<<ans<<'\n';
			for(long long i=1;i<=n;i++)e[i].clear(),m1[i]=m2[i]=0;
			continue;
		}
		for(long long st=0;st<(1<<n);st++){
			if(__builtin_popcount(st)!=k)continue;
			cur=0;
//			cout<<st<<'\n';
			for(long long i=1;i<=n;i++)is[i]=false,pp[i]=i,ct[i]=0;
			for(long long i=1;i<=n;i++)if((st>>i-1)&1)p[++cur]=i,is[i]=true;
			long long tot=0;
			for(long long i=1;i<=cur;i++){
				for(long long j=0;j<e[p[i]].size();j++){
					long long v=e[p[i]][j];
					if(is[v])merge(p[i],v);
				}
			}
			for(long long i=1;i<=cur;i++)ct[find(p[i])]++;
			for(long long i=1;i<=cur;i++)tot+=(ct[p[i]]>0);
			if(tot==2){
				long long res=0;
				for(long long i=1;i<=n;i++){
					long long cpp=2e18;
					for(long long j=1;j<=cur;j++){
						cpp=min(cpp,dist(p[j],i));
					}
					res=max(res,cpp);
				}
				ans=min(ans,res);
			}
		}
		cout<<ans<<'\n';
		for(long long i=1;i<=n;i++)e[i].clear();
	}
}
/*
my final score is 100+100+40+20=260
wish me get this true score pls
plsplsplsplsplsplspls
no make my score disappear
*/
