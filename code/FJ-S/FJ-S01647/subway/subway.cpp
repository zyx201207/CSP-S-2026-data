#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,u,v;
int w[500010];
int f[510][510];//存i到j的距离 
int f2[510][510];
int k[510];
int a[510][510];
int t[510][510];
void solve1(){
	int stu[5],num[510];
	int ans=1e9;
	for(int i=1;i<1<<n;i++){//暴力枚举铁路状态 
	    memset(f,0x3f,sizeof(f));
	    int x=i;
	    memset(num,0,sizeof(num));
	    for(int j=1;j<=n;j++){
	    	stu[j]=x%2;
	    	x/=2;
		}
		for(int j=1;j<=m;j++){
			if(stu[j]){
				for(int p=1;p<=k[j];p++){
					num[a[j][p]]++;//统计经过几次 
				}
			}
		}
		bool fc=false;
		for(int j=1;j<=m;j++){
			if(num[j]>d){//经过次数超了 
				fc=true;
				break;
			}
		}
		if(fc) continue;//该状态不可行
		for(int j=1;j<=n;j++){//加边 
			if(stu[j]){
				for(int p=1;p<=k[j];p++){
					for(int to=p+1;to<=k[j];to++){
						int x=a[j][p],y=a[j][to];
						f[x][y]=min(f[x][y],t[j][p]+t[j][to]);
						f[y][x]=f[x][y];//双向边 
					}
				}
			}
		} 
		for(int j=1;j<=m;j++) f[j][j]=0;//自己到自己为0 
		for(int j=1;j<=m;j++){//floyd暴力 
			for(int p=1;p<=m;p++){
				if(j==p) continue;
				for(int r=1;r<=m;r++){
					f[j][p]=min(f[j][p],f[j][r]+f[r][p]);
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int p=1;p<=m;p++){
				f2[j][p]=min(f2[j][p],f[j][p]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(cin>>c){
		memset(f2,0x3f,sizeof(f2)); 
		scanf("%d%d%d%d",&n,&m,&d,&q);
	    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	    for(int i=1;i<=n;i++){
		    scanf("%d",&k[i]);
		    for(int j=1;j<=k[i];j++){
			    scanf("%d%d",&a[i][j],&t[i][j]);
		    }
	    }
	    solve1();
	    for(int i=1;i<=q;i++){
			scanf("%d%d",&u,&v);
			printf("%d",f2[u][v]+w[u]+w[v]);
			if(i!=q) printf("\n");
		}
	}
	
	return 0;
}

