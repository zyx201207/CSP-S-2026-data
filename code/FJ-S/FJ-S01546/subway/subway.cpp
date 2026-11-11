#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long w;
	int to,next;
}e[10000007];
int first[500005],cnt;
int c,n,m,d,q,w[500005],k,a;//a指当前输入路线的站点编号
long long t,T[502][502]; //T表示路线间最短 
long long aa[21],tt[21];
void add(int u,int v,long long w){
	cnt++;
	e[cnt].w=w;
	e[cnt].to=v;
	e[cnt].next=first[u];
	first[u]=cnt;
	return;
}
long long ans;
void f(int x,int y){
	ans=1e18;
	int a1[21],a2[21],js1=0,js2=0;
	long long t1[21],t2[21];
	for(int i=first[x];i!=0;i=e[i].next)a1[++js1]=e[i].to-m,t1[js1]=e[i].w;
	for(int i=first[y];i!=0;i=e[i].next)a2[++js2]=e[i].to-m,t2[js2]=e[i].w;
	for(int i=1;i<=js1;i++){
		for(int j=1;j<=js2;j++){
			ans=min(ans,T[a1[i]][a2[j]]+t1[i]+t2[j]);
		}
	}
	ans+=w[x]+w[y];
	return;
}
int main(){
	freopen("subway7.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cin>>c>>n>>m>>d>>q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);//cin>>w[i];
	for(int i=1;i<=n;i++){
		scanf("%d",&k);//cin>>k;
		for(int j=1;j<=k;j++){
			scanf("%d %lld",&a,&t);//cin>>a>>t;
			add(a,m+i,t);
		}
	}
	
	int js=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			T[i][j]=T[j][i]=1e18; 
	for(int i=1;i<=m;i++){
		js=0;//该站点路线数 
		for(int j=first[i];j!=0;j=e[j].next){//找到一个站的所有路线 
			aa[++js]=e[j].to-m;//路线编号 
			tt[js]=e[j].w;
		}
		for(int u=1;u<=js;u++){
			for(int v=1;v<u;v++){//更新路线间 最短路 
				long long bjd=tt[u]+tt[v];
				if(T[aa[u]][aa[v]]>bjd){
					T[aa[u]][aa[v]]=T[aa[v]][aa[u]]=bjd;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)
			for(int l=1;l<=n;l++)
				T[j][i]=T[i][j]=min(T[i][j],T[i][l]+T[l][j]);
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d %d",&x,&y);//cin>>x>>y;
		f(x,y);
		printf("%lld\n",ans);//cout<<ans<<'\n';
	} 
	return 0;
}
