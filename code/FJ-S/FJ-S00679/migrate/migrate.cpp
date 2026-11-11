#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int c,T,n,ans,cnt;
long long d;
long long x[N];
long long mn[N],ci[N];
int hd[N],to[N],nxt[N],vis[N];
void add(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=hd[u];
	hd[u]=cnt;
}
void dfs(int p,int dis){
	//cout<<p<<" "<<dis<<"\n";
	if(dis==mn[p])ci[p]++;
	else if(dis<mn[p]){
		mn[p]=dis;
		ci[p]=1;
	}
	vis[p]=1;
	for(int i=hd[p];i;i=nxt[i]){
		int v=to[i];
		if(!vis[v])dfs(v,dis+1);
	}
	vis[p]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			hd[i]=0;
		}
		for(int i=1;i<=min(N,n*n);i++){
			to[i]=0;nxt[i]=0;
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					add(i,j);
					add(j,i);
					//cout<<"bian"<<i<<" "<<j<<" "<<x[i]<<" "<<x[j]<<"\n";
				}else{
					break;
				}
			}
		}
		for(int o=1;o<=n;o++){
			for(int j=1;j<=n;j++){
				vis[j]=0;mn[j]=INT_MAX;ci[j]=0;
			}
			dfs(o,0);
			//cout<<"\n";
			for(int j=o+1;j<=n;j++){
				if(j!=o){
					if(ci[j]==2){
						//cout<<o<<" "<<j<<"\n";
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
