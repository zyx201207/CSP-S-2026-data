#include<iostream>
#include<cstdio>
using namespace std;

#define int long long
//常数什么的无所谓了，怕挂 
const int maxn=500,maxk=5e5,maxm=1e6,maxK=1e3;
int w[maxK+5],k[maxn+5];
int a[maxn+5][maxK+5];
long long t[maxn+5][maxK+5],t2[maxn+5][maxK+5];
long long dis[maxK+5][maxK+5];
int cnt[maxk+5];
bool sp=false;
int lo[maxK+5];
int c,n,m,d,q;
int sss;//Banana Point 
bool zub[maxk+5];

struct Edge{
	int to,w;
	int next;
}e[maxm+5];
int head[maxk+5],ep=0;
bool vis[maxm+100];
void add(int u,int v,int w){
	e[++ep].to=v;
	e[ep].w=w;
	e[ep].next=head[u];
	head[u]=ep;
	if(sp){
		cnt[u]++,cnt[v]++;
		if(cnt[u]>4) sss=u;
		if(w==1) zub[u]=zub[v]=0;
		else zub[u]=zub[v]=1;
	}
}

void dfs(int s,int u,int k){
	for(int p=head[u]; p; p=e[p].next){
		int v=e[p].to,k2=e[p].w;
		if(vis[p]) continue;
		vis[p]=true;
		if(p&1) vis[p+1]=true;
		else vis[p-1]=true;
//		if(s==2&&k==0) cout<<v<<"\n";
//		if(s==2&&u==2&&v==1) cout<<k<<" "<<k2<<"\n";
		if(k2==k){ if(dis[s][u]<dis[s][v]) dis[s][v]=dis[s][u],lo[v]=k;}
		else{ if(dis[s][u]+t2[k][u]+t2[k2][u]<dis[s][v]){
			dis[s][v]=dis[s][u]+t2[k][u]+t2[k2][u],lo[v]=k2;
//			if(s==2&&u==2&&v==1) cout<<"???"<<t2[k][u]<<" "<<t2[k2][u]<<" "<<dis[s][u]<<" "<<dis[s][v]<<"\n";
		}}
		dfs(s,v,k2);
	}
}

void special_solve(){
	cout<<sss<<"\n";
	while(q--){
		int S,T;
		scanf("%lld%lld",&S,&T);
		if(S==sss) swap(S,T);
		long long ans=w[S]+w[T]+t2[(int)(zub[S])+1][S];
		if(T==sss) ans+=t2[(int)(zub[S])+1][T];
		else ans+=t2[(int)(zub[T]+1)][T];
		if(zub[S]==zub[T]||S==sss||T==sss) printf("%lld\n",ans);
		else printf("%lld\n",ans+t2[1][sss]+t2[2][sss]);
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(c==0||c==21||c==20) sp=true;
	for(int i=1; i<=m; i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%lld",&k[i]);
		for(int j=1; j<=k[i]; j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			if(j!=1) add(a[i][j-1],a[i][j],i);
			if(j!=1) add(a[i][j],a[i][j-1],i);
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=m; j++){
			t2[i][a[i][j]]=t[i][j];
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=m; j++){
			dis[i][j]=1e18;
		}
	}
	if(c==20||c==21){
		special_solve();
		return 0;
	}
	for(int i=1; i<=m; i++){
		dis[i][i]=0;
		for(int j=1; j<=ep; j++) vis[j]=false;
		dfs(i,i,0);
		for(int j=1; j<=m; j++) if(i!=j) dis[i][j]+=t2[lo[j]][j];
	}
/*	for(int i=1; i<=m; i++){
		for(int j=1; j<=m; j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	} */
	while(q--){
		int S,T;
		scanf("%lld%lld",&S,&T);
//		if(S>T) swap(S,T);
		printf("%lld\n",dis[S][T]+w[S]+w[T]);
	}
	return 0;
}//Expect: 52pts
