#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,x,y;
int w[505],s[505][505],t[505],z[505][25],zx[25],xz[505],lei[505];  //zx：站的线的数量      xz：线的站的数量 
int xx[505][25],sss[505];//第i线编号 
bool vis[505];                    //z[线][第i个站]=站编号            lei：该站累计的数量 

void dfs(int a,int ti){   //目前在a站，已用t时间 
	if(sss[505])t[a]=min(t[a],ti);
	sss[505]=1;
	if(a==y)
		return;
	
	for(int u=1;u<=zx[a];u++){  //u：线序号 
		int xian = xx[a][u]; 
		for(int p=1;p<=xz[xian];p++){  //p：站序号 
			int mubiao = z[xian][p];  //实际下一站 
			
			if(vis[mubiao])
				continue;
			
			ti=ti+s[mubiao][xian]+s[a][xian];
			vis[mubiao]=1;
			dfs(mubiao,ti);
			vis[mubiao]=0;
			ti=ti-s[mubiao][xian]-s[a][xian];
		}
	}
}

int main(){
	for(int i=1;i<=555;i++){
		t[505]=5555555;
	}
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		xz[i]=k;   //i号线的站的数量为k
		for(int j=1;j<=k;j++){
			int a,b;
			scanf("%d%d",&a,&b);  //a：站编号    b：i a线站通道t 
			s[a][i]=b;
			z[i][j]=a;
			zx[a]++;
			bool ok=1;
			for(int e=1;e<=lei[a];e++){
				if(xx[a][e]==i)ok=0;
			} 
			if(ok)xx[a][++lei[a]]=i;
		}
	}
	
	for(int i=1;i<=q;i++){
		memset(t,0,sizeof(t));
		memset(vis,0,sizeof(vis));
		ans=0;
		scanf("%d%d",&x,&y);
		ans+=w[x]+w[y];
		vis[x]=1;
		dfs(x,0);
		printf("%d\n",ans+t[y]);
		
	}
	return 0;
}
