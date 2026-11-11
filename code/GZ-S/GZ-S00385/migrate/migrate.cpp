//GZ-S00385
//张哲铭
//毕节梁才学校
#include<bits/stdc++.h>
using namespace std;
int n,d;
int c,T;
int g[3010][3010];
int num[3010][3010];
int a[2000000+10];
//。。。。。。。 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		int ans=0;
		scanf("%d%d",&n,&d);
		memset(num,0,sizeof(num));
		memset(g,0x3f,sizeof(g));
		for(int i=1;i<=n;i++)g[i][i]=0,scanf("%d",&a[i]);
		if(a[2]-a[1]<=d)g[1][2]=1;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-2]<=d)g[i-2][i]=1,num[i-2][i]=1;
			if(a[i]-a[i-1]<=d)g[i-1][i]=1,num[i-1][i]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(g[i][k]+g[k][j]<g[i][j])num[i][j]=1,g[i][j]=g[i][k]+g[k][j];
					else if(g[i][k]+g[k][j]==g[i][j])num[i][j]++; 
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(num[i][j]==2)ans++; 
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
