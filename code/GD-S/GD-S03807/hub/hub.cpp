#include<bits/stdc++.h>
#define int long long
#define MAXN 200005
using namespace std;
int head[MAXN],cnt,tc,T,n,k,d[MAXN],b[MAXN],c[MAXN],ans;
int deep[MAXN],fa[MAXN][22];
struct Node{
	int value,next;
}edge[MAXN];
void addedge(int u,int v){
	edge[++cnt].value=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int x,int fat){
	fa[x][0]=fat;deep[x]=deep[fat]+1;
	for(int i=1;i<=20;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=edge[i].next){
		int y=edge[i].value;
		if(y!=fat){
			dfs(y,x);
		}
	}
}
int LCA(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(deep[fa[x][i]]>=deep[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
int dis(int x,int y){
	int l=LCA(x,y);
	return deep[x]+deep[y]-deep[l]*2;
}
int sum,r[MAXN];
int find(int x){
	if(r[x]!=x)r[x]=find(r[x]);
	return r[x];
}
int check(){
	if(sum<k)return INT_MAX;
	//if(!(b[2]&&b[7]&&b[9]))return INT_MAX;//--
	for(int i=1;i<=n;i++)r[i]=i;
	for(int x=1;x<=n;x++){
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].value;
			if(b[x]&&b[y]){
				r[find(x)]=find(y);
			}
		}
	}
	int tcnt=0;
	for(int i=1;i<=n;i++){
		if(find(i)==i&&b[i])tcnt++;
	}
	if(tcnt>2)return INT_MAX;
	int tsum=0;
	/*for(int i=1;i<=k;i++)cout<<c[i]<<' ';
	cout<<"\n";*/
	for(int i=1;i<=n;i++){
		int minn=INT_MAX;
		for(int j=1;j<=k;j++){
			if(dis(i,c[j])<minn)minn=dis(i,c[j])/*,cout<<i<<' '<<c[j]<<' '<<minn<<"qminn\n"*/;
		}
		//cout<<i<<' '<<minn<<"minn\n";
		tsum=max(tsum,minn);
	}
	//cout<<"tsum!!!!"<<tsum<<"\n";
	return tsum;
}
void bdfs(int x){
	if(x==n+1){
		ans=min(ans,check());
		return;
	}
	if(sum<k){
		b[x]=1;
		c[++sum]=x;
		bdfs(x+1);
		sum--;
		b[x]=0;
	}
	bdfs(x+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&tc,&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)head[i]=edge[i].value=edge[i].next=0;
		cnt=0;ans=INT_MAX;
		for(int i=1;i<n;i++){
			int x,y;scanf("%lld%lld",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		dfs(1,0);
		bdfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}

