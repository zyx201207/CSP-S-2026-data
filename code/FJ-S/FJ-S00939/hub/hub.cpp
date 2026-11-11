#include<bits/stdc++.h>
using namespace std;
const long long N=105,inf=1e15;
long long c,t,n,k,u,v,dis[N][N],f[N],sum,num,ans,minn,maxx;
long long h[N],cnt;
struct hhh{
	int t,ne;
}b[N];
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
void add(int x,int y){
	b[++cnt].ne=h[x];
	h[x]=cnt;
	b[cnt].t=y;
}
void dfs1(int x,int y){
	for(int i=h[x];i;i=b[i].ne){
		if(f[b[i].t]<y){
			f[b[i].t]=y;
			dis[y][b[i].t]=dis[y][x]+1;
			dfs1(b[i].t,y);
		}
	}
}
void dfs2(int x){
	f[x]=0;
	for(int i=h[x];i;i=b[i].ne){
		if(f[b[i].t]!=0){
			dfs2(b[i].t);
		}
	}
}
void solve(){
	ans=inf;
	n=read();k=read();
	cnt=0;
	for(int i=1;i<=n;i++){
		h[i]=0;
	}
	for(int i=1;i<=n-1;i++){
		u=read();v=read();
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=0;
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
		dfs1(i,i);
	}
	for(int o=0;o<=(1<<n)-1;o++){
		sum=0;
		for(int j=1;j<=n;j++){
			if((o>>(j-1))&1==1){
				sum++;f[j]=1;
			}
		}
		if(sum!=k)continue;
		num=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1){
				num++;
				dfs2(i);
			}
		}
		if(num>2)continue;
		maxx=0;
		for(int i=1;i<=n;i++){
			if((o>>(i-1))&1==1)continue;
			minn=inf;
			for(int j=1;j<=n;j++){
				if((o>>(j-1))&1==1){
					minn=min(minn,dis[i][j]);
				}
			}
			maxx=max(maxx,minn);
		}
		ans=min(ans,maxx);
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		solve();
	}
	return 0;
}
