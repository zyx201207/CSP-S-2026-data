#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int maxn=2e6+5,inf=1e9;
int n,k,u,v,f[maxn];
vector<int>g[maxn];
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	f[fy]=fx;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<n;i++){
			u=read(),v=read();
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		if(k==2){
			int ans=inf;
			for(int x=1;x<=n;x++)for(int y=x+1;y<=n;y++){
				vector<int>ok(n+1,0);
				ok[x]=ok[y]=1;
				vector<vector<int>>dis(n+1,vector<int>(n+1,inf));
				for(int i=1;i<=n;i++)
					for(int j=0;j<g[i].size();j++){
						int v=g[i][j];
						dis[i][v]=dis[v][i]=1;
					}
				int res=0;
				for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
					if(i==j||j==k||i==k||dis[i][k]==inf||dis[k][j]==inf)continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
				for(int i=1;i<=n;i++){
					if(ok[i])continue;
					int mind=inf;
					for(int j=1;j<=n;j++)
						if(ok[j])mind=min(mind,dis[i][j]);
					res=max(res,mind);
				}
				ans=min(ans,res);
			}
			write(ans),putchar('\n');
			continue;
		}
		int ans=inf;
		for(int mask=0;mask<(1<<n);mask++){
			int cnt=0;
			vector<bool>ok(n+1,0);
			for(int j=1;j<=n;j++){
				ok[j]=((mask>>(j-1))&1);
				cnt+=ok[j];
			}
			if(cnt!=k)continue;
			vector<vector<int>>dis(n+1,vector<int>(n+1,inf));
			fill(f+1,f+n+1,-1);
			for(int i=1;i<=n;i++)
				if(ok[i])f[i]=i;
			for(int i=1;i<=n;i++){
				for(int j=0;j<g[i].size();j++){
					int v=g[i][j];
					dis[i][v]=dis[v][i]=1;
					if(!ok[v]||!ok[i])continue;
					merge(i,v);
				}
			}
			int ltcnt=0;
			for(int i=1;i<=n;i++)
				if(ok[i])ltcnt+=(find(i)==i);
			if(ltcnt>2)continue;
			int res=0;
			for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
				if(i==j||j==k||i==k||dis[i][k]==inf||dis[k][j]==inf)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
			for(int i=1;i<=n;i++){
				if(ok[i])continue;
				int mind=inf;
				for(int j=1;j<=n;j++)
					if(ok[j])mind=min(mind,dis[i][j]);
				res=max(res,mind);
			}
			ans=min(ans,res);
		}
		write(ans),putchar('\n');
	}
	return 0;
}
