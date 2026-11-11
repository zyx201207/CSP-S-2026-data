#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3005;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int c,T,n,K,d[N][N],dfn[N],ti,f[N];
vector<int> e[N];
void dfs(int x,int fr){
	dfn[x]=++ti;
	for(int i=0;i<e[x].size();i++){
		if(!dfn[e[x][i]] && e[x][i]!=fr && f[e[x][i]]) dfs(e[x][i],x);
	}
	return;
}
bool check(ll x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		f[i]=x&1;
		cnt+=f[i];
		x>>=1;
		dfn[i]=0;
	}
	if(cnt!=K){
		return false;
	}
	ti=cnt=0;
	for(int i=1;i<=n;i++){
		if(f[i] && !dfn[i]){
			cnt++;
			dfs(i,0);
		}
	}
	if(cnt>2){
		return false;
	}
	return true;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--){
		memset(d,0x3f,sizeof(d));
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		n=read(),K=read();
		for(int i=1,u,v;i<n;i++){
			u=read(),v=read();
			e[u].push_back(v),e[v].push_back(u);
			d[u][v]=d[v][u]=1;
		}
		for(int i=1;i<=n;i++){
			d[i][i]=0;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==k || i==j || k==j){
						continue;
					}
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
		int res=0x3fffffff;
		for(ll k=0;k<(1<<(n+1));k++){
			if(!check(k)){
				continue;
			}
			int maxn=0;
			for(int i=1;i<=n;i++){
				int dis=0x3fffffff;
				if(f[i]){
					continue;
				}
				for(int j=1;j<=n;j++){
					if(!f[j]){
						continue;
					}
					dis=min(dis,d[i][j]);
				}
				maxn=max(dis,maxn);
			}
			res=min(maxn,res);
		}
		printf("%d\n",res);
	}
	return 0;
}//de T1 zhe shi T4
