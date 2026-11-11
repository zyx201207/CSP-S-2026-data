#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
const int N=5005;
int c,n,m,d,q;
int w[N],dis[N][N];
int cost[N],st[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1; i<=m; i++) w[i]=read();
	for(int i=1; i<=n; i++){
		int k; k=read();
		for(int j=1; j<=k; j++){
			st[j]=read(); cost[j]=read();
		}
		for(int j=1; j<=k; j++){
			for(int p=j+1; p<=k; p++){
				dis[st[j]][st[p]]=dis[st[p]][st[j]]=cost[j]+cost[p];
//				cout<<st[j]<<" "<<st[p]<<" : "<<dis[st[j]][st[p]]<<endl;
			}
		}
	}
	for(int k=1; k<=m; k++){
		for(int i=1; i<=m; i++){
			for(int j=1; j<=m; j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1; i<=q; i++){
		int x,y;
		x=read(),y=read();
		printf("%lld\n",dis[x][y]+w[x]+w[y]);
	}
	return 0;
}

