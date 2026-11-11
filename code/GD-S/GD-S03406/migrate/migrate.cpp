#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000006]={};
int n,d;
int b=0;
int road(int s,int e,int l){
	if(s==e) return l;
	b=0;
	int x=INT_MAX;
	for(int i=s+1;i<=e;i++){
		if(a[i]-a[s]>d) break;
		int y=road(i,e,l+1);
		if(x>y){
			x=y;
			b=0;
		}else if(x==y){
			b++;
		}
	}
	return x;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	
	while(t--){
		int cnt=0;
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<n-1;i++){//至少留两个岛 
			for(int j=i+2;j<=n;j++){//终点 
				b=0;
				road(i,j,0);
				if(b==1){
//					printf("%d %d\n",i,j);
					cnt++;
				}
			} 
		}
		printf("%d\n",cnt);
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
