#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}

int n,m,d,q;
int w[500005];
int dis[505][505];

int du[500005];
signed to[500005][22];
int val[500005][22];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	read(); n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int K=read();
		for(int j=1;j<=K;j++){
			int x=read(); int y=read();
			du[x]++; to[x][du[x]]=i; val[x][du[x]]=y;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=du[i];j++){
			for(int k=1;k<j;k++){
				dis[to[i][j]][to[i][k]]=val[i][j]+val[i][k];
				dis[to[i][k]][to[i][j]]=val[i][k]+val[i][j];
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x=read(); int y=read();
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int j=1;j<=du[x];j++){
			for(int k=1;k<=du[y];k++){
//				cout<<"! "<<to[x][j]<<" "<<to[y][k]<<endl;
				ans=min(ans,val[x][j]+val[y][k]+dis[to[x][j]][to[y][k]]);
			}
		}
		write(ans+w[x]+w[y]); putchar('\n');
	}
	
	return 0;
}


// m*d^2 + n^3 +q*d^2 

// 第一遍写的时候 floyd 假了…… 大洋里测不出来啊 

