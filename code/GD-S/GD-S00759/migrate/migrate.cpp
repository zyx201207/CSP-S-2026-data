#include<bits/stdc++.h>
using namespace std;
int c,T,a,x[5005],d,f;
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c==11||c==12){
		while(T--){
			scanf("%d%d",&a,&d);
			f=0;
			for(int i=1;i<=a;i++){
				scanf("%d",&x[i]);
				if(i>2&&x[i]-x[i-1]>d){
					printf("0\n");
					f=1;
					break;
				}
			}
		}
	}
	while(T--){
		scanf("%d%d",&a,&d);
		f=0;
		int id=0;
		for(int i=1;i<=a;i++){
			scanf("%d",&x[i]);
			if(i>2&&x[i]-x[i-1]>d&&f==0){
				id=i-1;
				f=1;
			}
		}
		if(f==0) id=a;
		for(int i=1;i<id;i++){
			for(int j=i+1;j<=id;j++){
				
			}
		} 
	}
	return 0;
}

