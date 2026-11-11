#include<iostream>
#include<cstdio>
#include<queue>


using namespace std;

const int M=2e6+5;

int a[M],n,d;

int b[M],c[M];

void dfs(int u){
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]>d)break;
		int dis=b[u]+1;
		if(dis<b[i]){
			b[i]=dis;
			c[i]=1;
			dfs(i);
		}else if(dis==b[i]){
			c[i]++;
			dfs(i);
		}
	}
}

void work(){
	
	scanf("%d%d",&n,&d);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	
	int ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=0x7fffffff;
			c[j]=-1;
		}
		b[i]=0;
		c[i]=1;
		dfs(i);
		
//		printf("#:%d\n",i);
//		for(int j=1;j<=n;j++){
//			printf("%d ",c[j]);
//		}
//		printf("\n");
		
		for(int j=1;j<=n;j++){
			if(c[j]==2){
				ans++;
			}
		}
	}
	
	printf("%d\n",ans);
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int C,T;
	scanf("%d%d",&C,&T);
	
	while(T--){
		work();
	}
	
	return 0;
}

/*
0 1
4 2
1 2 3 4
*/
 
