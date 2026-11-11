#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll read(){
	ll ans=0,w=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-'){
			w=-w;
		}
		s=getchar();
	}
	while(isdigit(s)){
		ans=(ans<<3LL)+(ans<<1LL)+(s^48);
		s=getchar(); 
	}
	return ans*w;
}

const ll N=505,M=5e5+10,inf=1e15;
ll st[M][22],val[M][22];
ll dis[N][N];
ll w[M];
int c,n,m,d,q;
int ids[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			dis[i][j]=dis[j][i]=inf;
		}
	}
	
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			ids[a]++;
			st[a][ids[a]]=i,val[a][ids[a]]=t;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=ids[i];j++){
			for(int k=1;k<=ids[i];k++){
				if(j==k){
					continue;
				}
				int x=st[i][j],y=st[i][k];
				dis[x][y]=dis[y][x]=min(dis[x][y],val[i][j]+val[i][k]);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}

	while(q--){
		ll x=read(),y=read();
		ll ans=inf;
		for(int i=1;i<=ids[x];i++){
			for(int j=1;j<=ids[y];j++){
				ll l=st[x][i],r=st[y][j];
				ans=min(ans,dis[l][r]+val[x][i]+val[y][j]+w[x]+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
