#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int read() {
	int res=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int maxn=505,maxm=5e5+5,maxd=21;

int T,n,m,d,q;
int w[maxm];

int k[maxn],t[maxn][maxm];

vector<int> pass[maxm],past[maxn];

long long dist[maxn][maxn];

signed main() {
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	T=read(),n=read(),m=read(),d=read(),q=read();
	
	for(int i=1;i<=m;i++) w[i]=read();
	
	for(int i=1;i<=n;i++) {
		
		k[i]=read();
		int lst=0;
		
		for(int j=1;j<=k[i];j++) {
			
			int zhan=read(),sj=read();
			
			t[i][zhan]=sj;
			past[i].push_back(zhan);
			pass[zhan].push_back(i);
		}
	}
	
	for(int i=1;i<=n;i++) {
		
		for(int j=1;j<=n;j++) {
			
			if(i==j) continue;
			
			long long mi=inf;
			
			for(int tmp:past[i]) 
				if(t[j][tmp]!=0) mi=min(mi,t[j][tmp]+t[i][tmp]);
				
			if(mi==inf) dist[i][j]=inf;
			else dist[i][j]=mi,dist[j][i]=mi;
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

	while(q--) {
		
		int x=read(),y=read();
		
		long long ans=0x3f3f3f3f3f3f3f3f;
		
		for(int u:pass[x]) 
			for(int v:pass[y]) 
				ans=min(ans,dist[u][v]+w[x]+w[y]+t[u][x]+t[v][y]);
		
		write(ans),putchar('\n');
	}
	
	return 0;
}
