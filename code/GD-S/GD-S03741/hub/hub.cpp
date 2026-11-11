#include<bits/stdc++.h>
using namespace std;
const long long MAXN=30;
long long d[30],dp[30],fa[30][20],minn=1e18,ok[MAXN],vis[MAXN],c,t,n,k,x,y,hd[MAXN],cnt;
struct ll{
	long long to,nxt;
}v[MAXN];
void add(long long x,long long y){
	cnt++;
	v[cnt].to=y;
	v[cnt].nxt=hd[x];
	hd[x]=cnt;
}
void dfs1(long long pos){
	vis[pos]=1;
	for(long long i=hd[pos];i;i=v[i].nxt){
		long long p=v[i].to;
		if(vis[p] or !ok[p])continue;
		dfs1(p);
	}
}
void dfs2(long long pos,long long f,long long dd){
	dp[pos]=dd;
	fa[pos][0]=f;
	for(long long i=hd[pos];i;i=v[i].nxt){
		long long p=v[i].to;
		if(p==f)continue;
		dfs2(p,pos,dd+1); 
	}
}
long long lca(long long x,long long y){
	if(dp[x]<dp[y])swap(x,y);
	long long sum=0;
	while(dp[x]>dp[y]){
		sum++;
		x=fa[x][0];
	}
	while(x!=y){
		x=fa[x][0];
		y=fa[y][0];
		sum+=2;
	}
	return sum;
}
void dfs(long long pos,long long ha){
	if(pos==n+1){
		if(ha!=0)return;
		memset(vis,0,sizeof(vis));
		long long ci=0;
		for(long long i=1;i<=n;i++){
			if(!ok[i] or vis[i])continue;
			ci++;
			dfs1(i); 
		}
		if(ci>2)return;
		memset(dp,0,sizeof(dp));
		dfs2(1,0,1);
		for(long long i=1;i<=10;i++){
			for(long long j=1;j<=n;j++){
				fa[j][i]=fa[fa[j][i-1]][i-1];
			}
		}
		long long now=0;
		memset(d,0x3f,sizeof(d));
	/*	for(long long i=1;i<=n;i++){
			if(ok[i])cout<<i<<' ';
		}*/
	//	cout<<endl;
		for(long long i=1;i<=n;i++){
			if(ok[i]){
				d[i]=0;
				continue;
			}
			for(long long j=1;j<=n;j++){
				if(!ok[j])continue;
				d[i]=min(d[i],lca(i,j)); 
			}
			now=max(now,d[i]);
		}
		minn=min(minn,now);
		return;
	}
	if(ha){
		ok[pos]=1;
		dfs(pos+1,ha-1);
	}
	ok[pos]=0;
	dfs(pos+1,ha);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		minn=1e18;
		scanf("%lld%lld",&n,&k);
		memset(hd,0,sizeof(hd));
		cnt=0;
		for(long long i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,k);
		printf("%lld\n",minn);
	}
	return 0;
} 
