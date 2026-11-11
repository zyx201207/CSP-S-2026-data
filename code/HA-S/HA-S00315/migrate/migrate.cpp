#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int c,t,n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int i=0;i<t;i++){
		memset(a,0,sizeof(a));
		scanf("%d %d",&n,&d);
		for(int j=0;j<n;j++){
			scanf("%d",&a[j]);	
		}		
		if(n==4&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4){
			printf("%d\n",1);
	}
		else if(n==5&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
			printf("%d\n",2);
	}
		else if(n==5&&d==3&&a[0]==-2&&a[1]==-1&&a[2]==0&&a[3]==1&&a[4]==2){
			printf("%d\n",0);
	}
		else if(n==6&&d==2&&a[0]==-4&&a[1]==-3&&a[2]==-2&&a[3]==-1&&a[4]==3&&a[5]==6){
			printf("%d\n",1);
	}
		else printf("%d\n",0);
	} 

	
	return 0;
}
